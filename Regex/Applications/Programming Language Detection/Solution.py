import re
import sys

regex_java = r'import\s*java'
regex_c = r'#\s*include'
string = '\n'.join(sys.stdin.readlines())
if re.search(regex_c, string):
    print('C')
elif re.search(regex_java, string):
    print('Java')
else:
    print('Python')