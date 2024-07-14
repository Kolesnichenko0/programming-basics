//Array
#include <iostream>
#include "header.h"
#include <array>

using std::array;
using std::cout;

int main() {
    //Testing swapElements
    array<int, 4> array1 = { -2, 2, 5, 9};
    swapElements(array1, 1, 3);
    for (const auto& elem : array1) {
        cout << elem << " ";
    }
    cout << "\n";

    //Testing findElement
    array<double, 4> array2 = { 1.9, -1.3, 2.8, 11.2 };
    cout << "Element with value 11.2 found at index: " << findElement(array2, 11.2) << "\n";

    //Testing swapNeighbours
    array<char, 6> array3 = { 'o', 'r', 'a', 'n', 'g', 'e'};
    swapNeighbours(array3);
    for (const auto& elem : array3) {
        cout << elem << " ";
    }
    cout << "\n";

    return 0;
}