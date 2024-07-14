//Working with a linked list

#include <iostream>
#include <fstream>
#include <cmath>

struct Link {
    int data;
    Link* next;
};

//Deleting elems of a linked list from dynamic memory
void deleteLinkedList(Link* link) {
    Link* temp = link;
    while (link != nullptr) {
        link = temp;
        if (temp)
            temp = temp->next;
        delete link;
    }
}

int** arrayCompletion(const char* fileName, const int n,int &m) {
    //Opening a file
    std::ifstream inFile;
    inFile.open(fileName);
    if (!inFile.is_open()) {
        std::cerr << "Cannot open input file" << std::endl;
        exit(1);
    }
    int count = 0; // counter for finding the number of elements 
    Link* first = nullptr; // for the first node
    Link* last = nullptr; // for the last node
    Link* link; // for the current node

    //Reading from a file and entry into the linked list
    int value;
    while (inFile >> value) {
        count++;
        link = new Link;
        link->data = value;
        link->next = nullptr;
        if (last == nullptr)
            first = link;
        else {
            last->next = link;
        }
        last = link;
    }
    link = first;
    inFile.close();
    
    //Finding the number of rows
    if (count % n == 0)
        m = count / n;
    else
        m = count / n + 1;

    //Creating array in dynamic memory
    int** array = new int* [m];
    for (int i = 0; i < m; i++) {
        array[i] = new int[n];
    }

    //Array completion 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (link) {
                array[i][j] = link->data;
                link = link->next;
            }
            else {
                array[i][j] = 0;
            }
        }
    }
    link = first;
    deleteLinkedList(link);
    return array;
}

//Printing array
void printArray(int** array, const int n, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
        {
            std::cout << array[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

void printArray(double* cubicroots, const int n) {
    for (int i = 0; i < n; i++) {
        std::cout << cubicroots[i] << '\t';
    }
    std::cout << std::endl;
}

void writeToFile(int **array, const int n, int m, std::ofstream& outFile) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
        {
            outFile << array[i][j] << '\t';
        }
        outFile << std::endl;
    }
}

void writeToFile(double *cubicroots, const int n, std::ofstream& outFile) {
    for (int i = 0; i < n; i++) {
        outFile << cubicroots[i] << '\t';
    }
    outFile << std::endl;
}

bool checkingConverting(int** array, const int n, int m) {
    bool checkingConverting = false;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[i][j] % 2 == 0)
            {
                checkingConverting = true;
            }
        }
    }
    return checkingConverting;
}

void elemConversion(int** array, const int n, int m) {
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[i][j] % 2 == 0)
            {
                array[i][j] = pow(array[i][j], 2);
            }
        }
    }
}

void cubicRootsCompletion(int **array, double* cubicroots, const int n, int m) {
    int min_temp;
    for (int i = 0; i < n; i++) {
        min_temp = array[0][i];
        for (int j = 0; j < m; j++) {
            if (min_temp > array[j][i]) {
                min_temp = array[j][i];
            }
        }
        cubicroots[i] = cbrt(min_temp);
    }
}

int main()
{
    std::ofstream outFile;
    outFile.open("result.txt");
    if (!outFile.is_open()) {
        std::cerr << "Cannot open input file" << std::endl;
        return 1;
    }

    const int n = 5;
    int m = 0;
    int** array = arrayCompletion("data.txt", n, m);

    //Output of the initial array
    std::cout << "Initial array:" << std::endl;
    printArray(array, n ,m);

    //Checking whether the conversion is possible
    bool status = checkingConverting(array, n, m);

    if (status == false) {
        std::cerr << "There are no even numbers in the array, so conversion is impossible" << std::endl;
        return 1;
    }
    else {
        elemConversion(array, n, m); //element conversion
    }

    //Output of the converted array
    std::cout << "Converted array:" << std::endl;
    printArray(array, n, m);

    //Writing a convected array to a file
    outFile << "Converted array:" << std::endl;
    writeToFile(array, n, m, outFile);
    std::cout << "The array is written to the file result.txt" << std::endl;

    double* cubicroots = new double[n];

    //Completing an array with the cube roots of the minimum column elements
    cubicRootsCompletion(array, cubicroots, n, m);

    //Output of the cubicroots array
    std::cout << "Cubic roots array:" << std::endl;
    printArray(cubicroots, n);

    //Writing a cubicroots to a file
    outFile << "Cubic roots array:" << std::endl;
    writeToFile(cubicroots, n, outFile);
    std::cout << "The array is written to the file result.txt" << std::endl;

    //Deleting array and cubicroots from dynamic memory
    for (int i = 0; i < m; i++) {
        delete[] array[i];
    }
    delete[] array;
    delete[] cubicroots;

    outFile.close();
    return 0;
}
