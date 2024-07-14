//Presentation and processing of student data
#include <iostream>
#include <cstring>

struct Student {
    unsigned ID_number;
    char surname[20];
    int marks[6];
};

//Printing the data about the student
void printStudent(const Student &student, const int numberOfMarks) {
    std::cout << "Student ID number:" << student.ID_number << std::endl;
    std::cout << "Surname: " << student.surname << std::endl;
    std::cout << "Student's marks:" << std::endl;
    for (int i = 0; i < numberOfMarks; i++)
        std::cout << student.marks[i] << "\t";
    std::cout << std::endl;
}

//Calculating the average score
double CalculateAverageScore(const Student &students, const int numberOfMarks) {
    int sumOfMarks = 0;
    for (int i = 0; i < numberOfMarks; i++) {
        sumOfMarks += students.marks[i];
    }
    return sumOfMarks / numberOfMarks;
}

//Sorting by increasing average score
void sortByAverageMark(Student** students, int size, const int numberOfMarks) {
    bool status = true;
    while (status) {
        status = false;
        for (int i = 0; i < size - 1; i++) {
            if (CalculateAverageScore(*students[i], numberOfMarks) > CalculateAverageScore(*students[i + 1], numberOfMarks)) {
                Student* temp = students[i];
                students[i] = students[i + 1];
                students[i + 1] = temp;
                status = true;
            }
        }
    }

}

//Printing the data about students
void printStudents(Student** students, int size, const int numberOfMarks) {
    for (int i = 0; i < size; i++) {
        printStudent(*students[i], numberOfMarks);
    }
}

//Search for data on students with a surname length of less than 7 letters.
void printIf(Student** students, int size, const int numberOfMarks) {
    for (int i = 0; i < size; i++) {
        if (strlen(students[i]->surname) < 7)
            printStudent(*students[i], numberOfMarks);
    }
}

int main()
{
    const int n = 6;
    const int numberOfMarks = 6;
    Student students[n] = {
        {1, "Boolover", {67, 87, 65, 86, 78, 87}},
        {2, "Jonerova", {89, 90, 78, 86, 98, 65}},
        {3, "Mokylova", {76, 87, 98, 67, 90, 76}},
        {4, "Hokin", {76, 62, 78, 90, 67, 92}},
        {5, "Vokirera", {76, 71, 79, 92, 85, 76}},
        {6, "Botove", {89, 78, 76, 98, 85, 84}}
    };

    Student* pointers[n];
    for (int i = 0; i < n; i++)
        pointers[i] = &students[i];

    std::cout << "Initial list of students:\n";
    printStudents(pointers, n, numberOfMarks);
    sortByAverageMark(pointers, n, numberOfMarks);
    std::cout << std::endl;
    std::cout << "Sorted list of students by average score:\n";
    printStudents(pointers, n, numberOfMarks);
    std::cout << std::endl;
    std::cout << "Students with a surname length of less than 7 letters:\n";
    printIf(pointers, n, numberOfMarks);
    return 0;
}
