//Classes for students and groups
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <queue>
using std::string;
using std::vector;
class Group;

//Class for student representation
class Student {
    //Overloaded output operation on a stream
    friend std::ostream& operator<<(std::ostream& out, const Student& student);
private:
    unsigned int ID_number = 0;
    string surname = "";
    vector<int> grades = { };
    Group* group = nullptr; //Pointer to the object group
public:
    //Constrcuctors:
    Student() { }
    Student(unsigned int ID_number, const char* surname, vector<int> grades) :
        ID_number(ID_number), surname(surname), grades(grades) { }
    Student(unsigned int ID_number, string surname, vector<int> grades) :
        ID_number(ID_number), surname(surname), grades(grades) { }
    //Setters and getters:
    void setID_number(unsigned int ID_number) { this->ID_number = ID_number; }
    unsigned int getID_number() const { return ID_number; }

    void setSurname(const char* surname) { this->surname = surname; }
    void setSurname(string surname) { this->surname = surname; }
    string getSurname() const { return surname; }

    void setGrades(vector<int> grades) { this->grades = grades; }
    vector<int> getGrades() const { return grades; }

    void setGroup(Group* group) { this->group = group; }
    Group* getGroup() const { return group; }

    double getAverageGrade() const { return accumulate(grades.begin(), grades.end(), 0.0) / grades.size(); }
};


//Class for group representation
class Group {
    //Overloaded output operation on a stream
    friend std::ostream& operator<<(std::ostream& out, const Group& group);
private:
    string number = "";
    vector<Student> students = { };
public:
    //Constrcuctors:
    Group() {};
    Group(string number) : number(number) { }
    Group(const char* number) : number(number) { }

    //Setters and getters:
    void setNumber(const char* number) { this->number = number; }
    void setNumber(string number) { this->number = number; }
    string getNumber() const { return number; }

    //Overloaded operator for getting vector elements
    Student operator[](int index) const { return students.at(index); }

    void addStudent(Student student);

    //Sorting by increasing average score
    void sortByAverageGrade();
    //Finding students with a surname length of less than 7 letters.
    void findStudentsIf();
};

//for Student
std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << "Student ID number: " << student.ID_number << "\n";
    out << "Surname: " << student.surname << "\n";
    out << "Group index: " << student.group->getNumber() << "\n";
    out << "Grades: ";
    for (const int& grade : student.grades) {
        out << grade << "\t";
    }
    out << "\n\n";
    return out;
}

//for Group
std::ostream& operator<<(std::ostream& out, const Group& group) {
    out << "Group Index: " << group.number << "\n";
    out << "Number of students: " << group.students.size() << "\n";
    out << "Students: " << "\n\n";
    for (const Student& student : group.students) {
        out << student;
    }
    return out;
}

//Finding students with a surname length of less than 7 letters.
void Group::findStudentsIf() {
    for_each(students.begin(), students.end(), [](const Student &student) {
        if (student.getSurname().length() < 7)
            std::cout << student;
     });
}

//Sorting by increasing average score
void Group::sortByAverageGrade() {
    sort(students.begin(), students.end(),
        [](const Student &st1, const Student &st2) {return st1.getAverageGrade() < st2.getAverageGrade(); });
}

void Group::addStudent(Student student) {
    student.setGroup(this);
    students.push_back(std::move(student));
}

int main()
{
    std::cout << "Creating group..." << std::endl;
    Group group("033-B");
    
    group.addStudent(Student(1, "Boolover", vector<int>{ 67, 87, 65, 86, 78 }));
    group.addStudent(Student(2, "Jonerova", vector<int>{ 89, 90, 78, 86, 98 }));
    group.addStudent(Student(3, "Mokylova", vector<int>{ 76, 87, 98, 67, 90 }));
    group.addStudent(Student(4, "Hokin", vector<int>{ 76, 62, 78, 90, 67 }));
    group.addStudent(Student(5, "Vokirera", vector<int>{ 76, 71, 79, 92, 85 }));
    group.addStudent(Student(6, "Botove", vector<int>{ 89, 78, 76, 98, 85 }));


    std::cout << "Group with initial list of students:\n";
    std::cout << group;
    std::cout << std::endl;
    std::cout << "group[2]:\n";
    std::cout << group[2];
    std::cout << std::endl;
    group.sortByAverageGrade();
    std::cout << std::endl;
    std::cout << "Group with sorted list of students by average score:\n";
    std::cout << group;
    std::cout << std::endl;
    std::cout << "Students with a surname length of less than 7 letters:\n";
    group.findStudentsIf();

    return 0;
}