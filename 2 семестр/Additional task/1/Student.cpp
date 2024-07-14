module student;

import group;

std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << "Student ID number: " << student.ID_number << "\n";
    out << "Surname: " << student.surname << "\n";
    out << "Group number: " << student.group->getNumber() << "\n";
    out << "Grades: ";
    for (const int& grade : student.grades) {
        out << grade << "\t";
    }
    out << "\n\n";
    return out;
}

