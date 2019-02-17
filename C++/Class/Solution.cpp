#include <iostream>

class Student {
   private:
    int age, standard;
    std::string firstName, lastName;

   public:
    void setAge(int age) { this->age = age; }
    void setStandard(int standard) { this->standard = standard; }
    void setFirstName(std::string firstName) { this->firstName = firstName; }
    void setLastName(std::string lastName) { this->lastName = lastName; }

    int getStandard() { return this->standard; }
    int getAge() { return this->age; }
    std::string getFirstName() { return this->firstName; }
    std::string getLastName() { return this->lastName; }

    std::string to_string() {
        return std::to_string(this->age) + "," + this->firstName + "," +
               this->lastName + "," + std::to_string(this->standard);
    }
};

int main() {
    int age, standard;
    std::string first_name, last_name;

    std::cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.setAge(age);
    st.setStandard(standard);
    st.setFirstName(first_name);
    st.setLastName(last_name);

    std::cout << st.getAge() << "\n";
    std::cout << st.getLastName() << ", " << st.getFirstName() << "\n";
    std::cout << st.getStandard() << "\n";
    std::cout << "\n";
    std::cout << st.to_string();

    return 0;
}
