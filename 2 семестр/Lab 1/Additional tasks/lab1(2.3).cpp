//Presentation and processing of educational institutions data

#include <iostream>

class Institution {
public:
    char name[100];
    int number_of_students;
};

//Printing the data about the institution
void printInstitution(Institution& institution, const int n) {
    std::cout << "Institution name: " << institution.name << std::endl;
    std::cout << "Number of students: " << institution.number_of_students << std::endl;
}

//Printing the data about institutions
void printInstitutions(Institution** institutions, const int n) {
    for (int i = 0; i < n; i++) {
        printInstitution(*institutions[i], n);
    }
}

//Sorting by name
void sortByName(Institution** institutions, const int n) {
    bool status = true;
    while (status) {
        status = false;
        for (int i = 0; i < n - 1; i++) {
            if (strcmp(institutions[i]->name, institutions[i + 1]->name) > 0) {
                Institution* temp = institutions[i];
                institutions[i] = institutions[i + 1];
                institutions[i + 1] = temp;
                status = true;
            }
        }
    }
}

int main()
{
    std::setlocale(LC_ALL, "UKR");
    const int n = 3;
    Institution institutions[n] = {
        {"Харкiвський нацiональний унiверситет радiоелектронiки", 7000 },
        {"Харкiвський нацiональний медичний унiверситет", 7000 },
        {"Нацiональний технiчний унiверситет \"Харкiвський полiтехнiчний iнститут\"", 20000 }
    };
    Institution *pointers[n];
    for (int i = 0; i < n; i++)
        pointers[i] = &institutions[i];
    std::cout << "Initial list of institutions:\n";
    printInstitutions(pointers, n);
    sortByName(pointers, n);
    std::cout << std::endl;
    std::cout << "Sorted list of institutions by name:\n";
    printInstitutions(pointers, n);
    std::cout << std::endl;
    return 0;

}
