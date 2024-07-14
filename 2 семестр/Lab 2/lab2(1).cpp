//Point3D
#include <iostream>
#include <cmath>

class Point3D {
    friend double operator-(const Point3D& point1, const Point3D& point2);
private:
    double x, y, z;
public:
    //The constructor without parameters
    Point3D() : x(0), y(0), z(0) {}
    //The constructor with 3 parameters
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
    //Methods for setting and getting coordinate values
    void setValueX(double x) { this->x = x; }
    double getValueX() const { return x; }
    void setValueY(double y) { this->y = y; }
    double getValueY() const { return y; }
    void setValueZ(double z) { this->z = z; }
    double getValueZ() const { return z; }

};

//Overloading the operator '-' for calculating the distance between two points
double operator-(const Point3D& point1, const Point3D& point2) {
    return std::sqrt(pow((point2.x - point1.x), 2) + pow((point2.y - point1.y), 2) + pow((point2.z - point1.z), 2));
}

int main()
{
    //Creating two points: point1 with default coordinates using the constructor without parameters, 
    //point2 with specified coordinates using constructor with 3 parameters
    Point3D point1;
    Point3D point2(2.5, 3.5, 1.5);

    point1.setValueX(1.0);
    point1.setValueY(1.0);
    point1.setValueZ(1.0);
    std::cout << "Point 1 has coordinates (" << point1.getValueX() << ", " << point1.getValueY() << ", " << point1.getValueZ() << ")" << std::endl;
    std::cout << "Point 2 has coordinates (" << point2.getValueX() << ", " << point2.getValueY() << ", " << point2.getValueZ() << ")" << std::endl;
    
    //Calculating the distance between point1 and point2 using the overloaded '-' operator
    double distance = point2 - point1;
    std::cout << "Distance between two points = " << distance << std::endl << std::endl;

    std::cout << "Changing the cooridanates of the point 1..." << std::endl;
    point1.setValueX(2.5);
    point1.setValueY(3.5);
    point1.setValueZ(1.5);
    std::cout << "Point 1 has coordinates (" << point1.getValueX() << ", " << point1.getValueY() << ", " << point1.getValueZ() << ")" << std::endl;
    
    //Calculating the distance between two points by explicitly calling the operator-() function
    distance = operator-(point1, point2);
    std::cout << "Distance between two points = " << distance << std::endl;

    return 0;
}
