//Class hierarchy

#include <iostream>
#include <cstring>

using std::cout;

//Class for human representation
//Class Human is the base class for our hierarchy
class Human {
protected:
    char* name;
    double height;
    double weight;
public:
    //Constructor that initialises all protected fields
    Human(const char* name, double height, double weight) : height(height), weight(weight) {
        this->name = new char[strlen(name) + 1]; //dynamic memory allocation for an array of characters with name
        strcpy_s(this->name, strlen(name) + 1, name);
    }
    //Getters
    char* getName() const { return name; };
    double getHeight() const { return height; }
    double getWeight() const { return weight; }

    //Virtual method that prints information about a human
    virtual void printInfo() {
        cout << "Name: " << name << "\n";
        cout << "Height: " << height << " cm\n";
        cout << "Weight: " << weight << " kg\n";
    }

    //Virtual destructor for correct work with dynamic memory
    virtual ~Human() {
        delete[] name;
    }
};

//Class for citizen representation
//class Citizen is a descendant of the class Human
class Citizen : public Human {
protected:
    char* nationality;
public:
    //Constructor that initialises all protected fields, including those of the base class
    Citizen(const char* name, double height, double weight, const char* nationality) : Human(name, height, weight) {
        this->nationality = new char[strlen(nationality) + 1]; //dynamic memory allocation for an array of characters with nationality
        strcpy_s(this->nationality, strlen(nationality) + 1, nationality);
    }

    //Getter
    char* getNationality() const { return nationality; };

    //Overridden method for printing information
    void printInfo() override {
        //Call the base class method for printing the common human information
        Human::printInfo();
        cout << "Nationality: " << nationality << "\n";
    }

    //Overridden destructor of a base class
    ~Citizen() override {
        delete[] nationality;
    }
};

//Class for student representation
//class Student is a descendant of the class Citizen
class Student : public Citizen {
protected:
    char* university;
    int ID_number;
public:
    //Constructor that initialises all protected fields, including those of the base class
    Student(const char* name, double height, double weight, const char* nationality, const char* university, int ID_number) 
        : Citizen(name, height, weight, nationality), ID_number(ID_number) {
        this->university = new char[strlen(university) + 1]; //dynamic memory allocation for an array of characters with university
        strcpy_s(this->university, strlen(university) + 1, university);
    }

    //Getters
    char* getUniversity() const { return university; };
    int getID_number() const { return ID_number; }

    //Overridden method for printing information
    void printInfo() override {
        //Call the base class method for printing the common citizen information
        Citizen::printInfo(); 
        cout << "University: " << university << "\n";
        cout << "Student ID number: " << ID_number << "\n";
    }
    
    //Overridden destructor of a base class
    ~Student() override {
        delete[] university;
    }
};

//Class for employee representation
//class Employee is a descendant of the class Citizen
class Employee : public Citizen {
protected:
    char* company;
public:
    //Constructor that initialises all protected fields, including those of the base class
    Employee(const char* name, double height, double weight, const char* nationality,const char *company)
        : Citizen(name, height, weight, nationality) {
        this->company = new char[strlen(company) + 1]; //dynamic memory allocation for an array of characters with company
        strcpy_s(this->company, strlen(company) + 1, company);
    }

    //Getter
    char* getCompany() const { return company; };

    //Overridden method for printing information
    void printInfo() override {
        //Call the base class method for printing the common citizen information
        Citizen::printInfo();
        cout << "Company: " << company << "\n";
    }

    //Overridden destructor of a base class
    ~Employee() override {
        delete[] company;
    }
};
int main()
{
    const int N = 4;
    //Creating an array of pointers to different hierarchy objects.
    Human* humans[N] = {
        new Human("Tom", 178, 66.2),
        new Citizen("Thomas", 162.5, 50.2, "Italian"),
        new Student("Pavlo", 190.7, 70.8, "Ukrainian", "NTU \"Kharkiv Polytechnic Institute\"", 435),
        new Employee("Dmitriy", 189.4, 68.2, "Ukrainian", "GlobalLogic"),
    };

    cout << "Information about Humans: \n";
    for(int i = 0; i < N; i++) {
        humans[i]->printInfo();
        cout << "\n";
    }

    //Printing student ID_number(humans[2]) 
    cout << "Test:\nStudent ID number: " << dynamic_cast<Student*>(humans[2])->getID_number() << "\n";

    for (int i = 0; i < N; i++) {
        //Deleting the object pointed to by the humans array element
        delete humans[i];
    }
    return 0;
}

