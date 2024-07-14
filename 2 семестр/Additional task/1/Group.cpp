module group;

std::ostream& operator<<(std::ostream& out, const Group& group) {
    out << "Group number: " << group.number << "\n";
    out << "Number of students: " << group.students.size() << "\n";
    out << "Students: " << "\n\n";
    for (const Student& student : group.students) {
        out << student;
    }
    return out;
}

//Finding students with a surname length of less than 7 letters.
void Group::findStudentsIf() {
    for_each(students.begin(), students.end(), [](const Student& student) {
        if (student.getSurname().length() < 7)
            std::cout << student;
        });
}

//Sorting by increasing average score
void Group::sortByAverageGrade() {
    sort(students.begin(), students.end(),
        [](const Student& st1, const Student& st2) {return st1.calculateAverageGrade() < st2.calculateAverageGrade(); });
}

void Group::addStudent(Student student) {
    student.setGroup(this);
    students.push_back(std::move(student));
}