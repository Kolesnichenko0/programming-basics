//Classes for students and groups
#include <iostream>
#include <cstring>

const int MAX_NUM_OF_STUDENTS = 50;
class Group;

//Class for student representation
class Student {
    //Overloaded output operation on a stream
    friend std::ostream& operator<<(std::ostream& out, const Student &student);
    //Overloaded operation of comparing two students
    friend bool operator>(Student &student1, Student &student2);
private:
    unsigned int ID_number = 0;
    char* surname = nullptr;
    int* grades = nullptr;
    Group* group = nullptr; //Pointer to the object group
public:
    static const int number_of_grades = 5;
    //Constrcuctors:
    //The constructor without parameters
    Student() { }
    Student(unsigned int ID_number, const char* surname, int* grades, Group* group);
    Student(Student& other);

    //Destructor
    ~Student();

    //Setters and getters:
    void setID_number(unsigned int ID_number) { this->ID_number = ID_number; }
    unsigned int getID_number() const { return ID_number; }
    void setSurname(const char *surname);
    char* getSurname() const { return surname; }
    void setGrades(int* grades);
    int* getGrades() const { return grades; }
    void setGroup(Group* group) { this->group = group; }
    Group* getGroup() const { return group; }
    
    //Overloaded assignment operator
    const Student& operator=(const Student& other);
};

//The constructor with 4 parameters
Student::Student(unsigned int ID_number, const char* surname, int* grades, Group* group) {
    setID_number(ID_number);
    setSurname(surname);
    setGrades(grades);
    setGroup(group);
}

//Copy constructor
Student::Student(Student& other) {
    this->ID_number = other.ID_number;
    this->surname = new char[strlen(other.surname) + 1];
    strcpy_s(this->surname, strlen(other.surname) + 1, other.surname);
    grades = new int[number_of_grades];
    for (int i = 0; i < number_of_grades; i++) {
        grades[i] = other.grades[i];
    }
    this->group = other.group;
}

//Destructor
Student::~Student() {
    //Deleting the student's name and grades from memory (if arrays were created)
    if (this->surname != nullptr) {
        delete[] surname;
    }
    if (this->grades != nullptr) {
        delete[] grades;
    }
}

void Student::setSurname(const char* surname) {
    //Deleting the surname (if the surname was)
    if (this->surname != nullptr) {
        delete[] this->surname;
    }
    //Creating a new array and writing a new surname
    this->surname = new char[strlen(surname) + 1];
    strcpy_s(this->surname, strlen(surname) + 1, surname);
}

void Student::setGrades(int* grades) {
    //Deleting grades (if grades was)
    if (this->grades != nullptr) {
        delete[] this->grades;
    }
    //Creating a new array and writing new grades
    this->grades = new int[number_of_grades];
    for (int i = 0; i < number_of_grades; i++) {
        this->grades[i] = grades[i];
    }
}

const Student& Student::operator=(const Student& other) {
    if (&other != this) {
        setID_number(other.ID_number);
        setSurname(other.surname);
        setGrades(other.grades);
        setGroup(other.group);
    }
    return *this;
}

bool operator>(Student& student1, Student& student2) {
    int sumOfGrades1 = 0;
    int sumOfGrades2 = 0;
    //Calculating the sum of the grades
    for (int i = 0; i < Student::number_of_grades; i++) {
        sumOfGrades1 += student1.grades[i];
        sumOfGrades2 += student2.grades[i];
    }
    return sumOfGrades1 > sumOfGrades2;
}

//Class for group representation
class Group {
    //Overloaded output operation on a stream
    friend std::ostream& operator<<(std::ostream& out, Group& group);
private:
    int index = 0;
    Student* students[MAX_NUM_OF_STUDENTS] = {}; //Array of student pointers
    int count = 0; //Number of pointers in the array
public:
    //Constrcuctors:
    //The constructor without parameters
    Group() {};
    Group(int index, Student* students[], int count);

    //Setters and getters:
    void setIndex(int index) { this->index = index; }
    int getIndex() const { return index; }
    void setStudents(Student* students[], int count);

    //Overloaded indexing operation
    Student* operator[](int student_index) const { return students[student_index]; }

    //Overloaded assignment operator
    const Group& operator=(const Group& other);
    
    //Sorting by increasing average score
    void sortByAverageGrade();
    //Finding students with a surname length of less than 7 letters.
    void findStudentsIf() const;
};

//The constructor with 3 parameters
Group::Group(int index, Student* students[], int count) {
    setIndex(index);
    setStudents(students, count);
}

//Getting from the parameter and filling in an array of pointers to students 
void Group::setStudents(Student* students[], int count) {
    this->count = count;
    for (int i = 0; i < count; i++) {
        this->students[i] = students[i];
        this->students[i]->setGroup(this);
    }
}

//for Student
std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << "Student ID number: " << student.ID_number << "\n";
    out << "Surname: " << student.surname << "\n";
    out << "Group index: " << student.group->getIndex() << "\n";
    out << "Grades: ";
    for (int i = 0; i < student.number_of_grades; i++) {
        out << student.grades[i] << "\t";
    }
    out << "\n\n";
    return out;
}

//for Group
std::ostream& operator<<(std::ostream& out, Group& group) {
    out << "Group Index: " << group.index << "\n";
    out << "Number of students: " << group.count << "\n";
    out << "Students: " << "\n\n";
    for (int i = 0; i < group.count; i++) {
        out << *(group.students[i]);
    }
    return out;
}

const Group& Group::operator=(const Group& other) {
    if (&other != this) {
        index = other.index;

        //Copying all Student objects from other
        for (int i = 0; i < other.count; i++) {
            students[i] = new Student(*other.students[i]); //Using copy constructor
            students[i]->setGroup(this);
        }

        count = other.count;
    }
    return *this;
}

//Finding students with a surname length of less than 7 letters.
void Group::findStudentsIf() const {
    for (int i = 0; i < count; i++) {
        if (strlen(students[i]->getSurname()) < 7)
            std::cout << *students[i];
    }
}

//Sorting by increasing average score
void Group::sortByAverageGrade() {
    bool mustSort = true;
    while (mustSort) {
        mustSort = false;
        for (int i = 0; i < count - 1; i++) {
            if (*(students[i]) > *(students[i+1])) { //Using operation of comparing
                std::swap(students[i], students[i + 1]);
                mustSort= true;
            }
        }
    }

}

//Filling an array of pointers to students
void createStudents(Student* students[]) {
    int grades1[Student::number_of_grades] = { 67, 87, 65, 86, 78 };
    int grades2[Student::number_of_grades] = { 89, 90, 78, 86, 98 };
    int grades3[Student::number_of_grades] = { 76, 87, 98, 67, 90 };
    int grades4[Student::number_of_grades] = { 76, 62, 78, 90, 67 };
    int grades5[Student::number_of_grades] = { 76, 71, 79, 92, 85 };
    int grades6[Student::number_of_grades] = { 89, 78, 76, 98, 85 };
    //Creating student objects in dynamic memory 
    students[0] = new Student(1, "Boolover", grades1, nullptr);
    students[1] = new Student(2, "Jonerova", grades2, nullptr);
    students[2] = new Student(3, "Mokylova", grades3, nullptr);
    students[3] = new Student(4, "Hokin", grades4, nullptr);
    students[4] = new Student(5, "Vokirera", grades5, nullptr);
    Student Student1(6, "Botove", grades6, nullptr);
    Student Student2 = Student1; //Using copy constructor
    students[5] = new Student(Student2); //Using copy constructor

    Student1 = *students[4]; //Using the assignment operation
} //For Student1 and Student2 the destructor is called when the createStudents function is finished

int main()
{
    std::cout << "Creating group1" << std::endl;
    Group group1;
    const int real_num_of_students_gr1 = 6; //Number of students in gr1
    Student* students_gr1[real_num_of_students_gr1]; //Creating an array of pointers to students in gr1
    createStudents(students_gr1);

    group1.setStudents(students_gr1, real_num_of_students_gr1);
    group1.setIndex(572);

    std::cout << "Group with initial list of students:\n";
    std::cout << group1;
    group1.sortByAverageGrade();
    std::cout << std::endl;
    std::cout << "Group with sorted list of students by average score:\n";
    std::cout << group1;
    std::cout << std::endl;
    std::cout << "Students with a surname length of less than 7 letters:\n";
    group1.findStudentsIf();

    std::cout << "Creating group2"<<std::endl;
    Group group2;
    const int real_num_of_students_gr2 = 2; //Number of students in gr2
    Student* students_gr2[real_num_of_students_gr2]; //Creating an array of pointers to students in gr2

    int grades1_gr2[Student::number_of_grades] = { 60, 82, 83, 86, 79 };
    int grades2_gr2[Student::number_of_grades] = { 78, 92, 78, 78, 100 };

    //Creating student objects in dynamic memory 
    students_gr2[0] = new Student(1, "Lonov", grades1_gr2, nullptr);
    students_gr2[1] = new Student(2, "Sorokov", grades2_gr2, nullptr);

    group2.setStudents(students_gr2, real_num_of_students_gr2);
    group2.setIndex(672);

    std::cout << group2;
    std::cout << std::endl;

    std::cout << "group2 = group1\n";
    group2 = group1; //Using the assignment operation

    std::cout << group2;

    for (int i = 0; i < real_num_of_students_gr1; i++)
    {
        //Deleting the object pointed to by the students_gr1 array element
        delete students_gr1[i];
    }

    for (int i = 0; i < real_num_of_students_gr2; i++)
    {
        //Deleting the object pointed to by the students_gr2 array element
        delete students_gr2[i];
    }

    return 0;
}