export module group;

import std;
import student;

using std::string;
using std::vector;

//Class for group representation
export class Group {
    //Overloaded output operation on a stream
    friend std::ostream& operator<<(std::ostream& out, const Group& group);
private:
    string number = "";
    vector<Student> students = { };
public:
    //Constrcuctors:
    Group() { }
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
