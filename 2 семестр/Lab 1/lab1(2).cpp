//3D-Points

#include <iostream>
#include <cmath>

struct Point {
    double x, y, z;
};

double sqr(double a) {
    return a * a;
}

//Calculating the distance between two points
double distance(Point p1, Point p2) {
    return std::sqrt(sqr(p2.x - p1.x) + sqr(p2.y - p1.y) + sqr(p2.z - p1.z));
}

int main()
{
    Point p1, p2;
    std::cout << "To calculate the distance between two points:\n";

    std::cout << "Enter the coordinates of point 1:\n";
    std::cout << "x1 = ";
    if (!(std::cin >> p1.x)) { // Checking for value validity
        std::cerr << "Error: Invalid value\n";
        return 1;
    }
    std::cout << "y1 = ";
    if (!(std::cin >> p1.y)) { // Checking for value validity
        std::cerr << "Error: Invalid value\n";
        return 1;
    }
    std::cout << "z1 = ";
    if (!(std::cin >> p1.z)) { // Checking for value validity
        std::cerr << "Error: Invalid value\n";
        return 1;
    }

    std::cout << "Enter the coordinates of point 2:\n";
    std::cout << "x2 = ";
    if (!(std::cin >> p2.x)) { // Checking for value validity
        std::cerr << "Error: Invalid value\n";
        return 1;
    }
    std::cout << "y2 = ";
    if (!(std::cin >> p2.y)) { // Checking for value validity
        std::cerr << "Error: Invalid value\n";
        return 1;
    }
    std::cout << "z2 = ";
    if (!(std::cin >> p2.z)) { // Checking for value validity
        std::cerr << "Error: Invalid value\n";
        return 1;
    }

    std::cout << "Distance = " << distance(p1, p2) << std::endl;
    return 0;
}
