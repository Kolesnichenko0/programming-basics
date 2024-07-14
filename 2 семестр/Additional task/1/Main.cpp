//Колесниченко Денис Євгенович, КН-222б
import std;
import student;
import group;

using std::vector;

int main() {
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
    std::cout << "Group with sorted list of students by average score:\n";
    std::cout << group;
    std::cout << std::endl;
    std::cout << "Students with a surname length of less than 7 letters:\n";
    group.findStudentsIf();

    return 0;
}