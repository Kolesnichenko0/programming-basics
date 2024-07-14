//Calculating the sum of the entered values

#include <iostream>

//Class for the calculation of the sum of the entered values
class SumOfElements {
private:
    int data;
    static int sum_of_elements; //Static variable for storing the sum of elements
public:
    //Constructor with 1 parameter
    SumOfElements(int data) : data(data) { sum_of_elements += data;}
    int getData() const { return data; }
    //Static method for getting the sum_of_elements
    static int sumOfElements() { return sum_of_elements; }

};

//Initialising the static variable sum_of_elements
int SumOfElements::sum_of_elements = 0;

int main()
{
    SumOfElements elem1(1);
    SumOfElements elem2(-1);
    SumOfElements elem3(10);
    SumOfElements elem4(9);
    SumOfElements elem5(-7);
    SumOfElements elem6(8);
    std::cout << "Sum of all elements = " << SumOfElements::sumOfElements() << std::endl;
    return 0;
}
