#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

class ParseTreeNode {
   private:
    string mTag;
    map<string, string> mAttributes;
    map<string, ParseTreeNode *> mNestedTags;

    void removeCharsFromString(string &str, const char *charsToRemove) {
        for (unsigned int i = 0; i < strlen(charsToRemove); ++i) {
            str.erase(remove(str.begin(), str.end(), charsToRemove[i]),
                      str.end());
        }
    }

    void addTag(ParseTreeNode *node, string tag) {
        ParseTreeNode *newTag = new ParseTreeNode(tag);
        node->mNestedTags.insert(pair<string, ParseTreeNode *>(tag, newTag));
    }

    void addAttribute(ParseTreeNode *node, string attribute, string value) {
        node->mAttributes.insert(pair<string, string>(attribute, value));
    }

    ParseTreeNode *getNodeFromName(string tag) {
        // eliminate attribute if present
        size_t previousIndex = 0;
        auto currentIndex = tag.find('~');
        if (currentIndex != string::npos) tag = tag.substr(0, currentIndex);

        string currTag;
        ParseTreeNode *requiredNode = this;
        currentIndex = tag.find('.');

        // iterate untill the last tag
        bool flag = true;
        while (currentIndex != string::npos or flag) {
            if (currentIndex == string::npos) flag = false;
            if (flag) {
                currTag =
                    tag.substr(previousIndex, currentIndex - previousIndex);
                if (requiredNode->mNestedTags.count(currTag) != 1)
                    return nullptr;
                requiredNode = requiredNode->mNestedTags.at(currTag);
                currentIndex++;
                previousIndex = currentIndex;
                currentIndex = tag.find('.', currentIndex);
            } else {
                currTag = tag.substr(previousIndex, tag.size());
                if (requiredNode->mNestedTags.count(currTag) == 1)
                    requiredNode = requiredNode->mNestedTags.at(currTag);
                else
                    return nullptr;
            }
        }
        return requiredNode;
    }

    string getValueFromName(string attribute) {
        size_t index = attribute.find('~');
        if (index == string::npos) return "Not Found!";
        index++;
        attribute = attribute.substr(index, attribute.size() - index);
        size_t count = mAttributes.count(attribute);
        if (count == 1)
            return mAttributes.at(attribute);
        else
            return "Not Found!";
    }

   public:
    ParseTreeNode(const string name) : mTag(name) {}
    ~ParseTreeNode() {}

    void parse(string line) {
        size_t size = line.size();
        stack<ParseTreeNode *> stack;
        stack.push(this);
        size_t currIndex = 0;
        size_t lookahead = 0;
        while (currIndex < size) {
            if (line[currIndex] == '<') {
                if (line[currIndex + 1] == '/') {
                    stack.pop();
                    currIndex = line.find('>', currIndex);
                } else
                    currIndex++;
            } else if (line[currIndex] == '>' or line[currIndex] == ' ') {
                currIndex++;
            } else if (currIndex < size - 1) {
                lookahead = line.find(' ', currIndex);
                lookahead = min(lookahead, line.find('>', currIndex));
                bool noAttributeFlag = true;
                while (lookahead < size) {
                    if (line[lookahead] == ' ') {
                        lookahead++;
                        noAttributeFlag = false;
                    } else if (line[lookahead] == '=') {
                        string attribute =
                            line.substr(currIndex, lookahead - currIndex - 1);

                        currIndex = lookahead + 2;
                        lookahead = line.find(' ', currIndex);
                        lookahead = min(lookahead, line.find('>', currIndex));

                        string value =
                            line.substr(currIndex, lookahead - currIndex);
                        removeCharsFromString(value, "\"");
                        addAttribute(stack.top(), attribute, value);
                        currIndex = lookahead;
                        break;
                    } else if (line[lookahead] != '=') {
                        string tag;
                        if (noAttributeFlag)
                            tag = line.substr(currIndex, lookahead - currIndex);
                        else
                            tag = line.substr(currIndex,
                                              lookahead - currIndex - 1);

                        addTag(stack.top(), tag);
                        stack.push(stack.top()->mNestedTags.at(tag));
                        currIndex = lookahead;
                        break;
                    }
                }
            }
        }
    }

    string getTagAttributeValue(string line) {
        ParseTreeNode *node = getNodeFromName(line);
        if (node == nullptr)
            return "Not Found!";
        else
            return node->getValueFromName(line);
    }
};

int main(int argc, char const *argv[]) {
    size_t lines, queries;
    string file = "";
    string line;

    cin >> lines >> queries;
    cin.ignore();

    ParseTreeNode root("root");

    for (size_t i = 0; i < lines; i++) {
        getline(cin, line);
        file += line;
    }

    root.parse(file);
    for (size_t i = 0; i < queries; i++) {
        cin >> line;
        cout << root.getTagAttributeValue(line) << '\n';
    }
    return 0;
}
