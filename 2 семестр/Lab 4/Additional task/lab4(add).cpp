#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    multimap<string, string> students;

    //Adding student data
    students.insert(make_pair("Botov", "Ivan"));
    students.insert(make_pair("Petrov", "Fedt"));
    students.insert(make_pair("Botov", "Tom"));
    students.insert(make_pair("Fykov", "Oleg"));
    students.insert(make_pair("Tynskiy", "Sergey"));

    //Check for people with the same last name
    for (auto it = students.begin(); it != students.end(); it++) {
        if (students.count(it->first) > 1) {
            cout << "There are students with the same last name in the group." << endl;
            break;
        }
    }

    //Print data about students by last name alphabet
    cout << "Students are listed in alphabetical order by last name:" << endl;
    for (auto it = students.begin(); it != students.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}