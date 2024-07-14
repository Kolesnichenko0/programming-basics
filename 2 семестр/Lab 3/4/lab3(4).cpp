#include <iostream>
#include "matrix.h"
#include "fraction.h"

//Individual task realisation
template<typename someType> void elemConversion(Matrix<someType>& matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            //The std::floor() function finds the largest integer that is not greater than the specified real number
            //check if the number is an integer
            if (std::floor(matrix(i, j)) == matrix(i, j) && static_cast<int>(matrix(i, j)) % 2 == 0) {
                matrix(i, j) = pow(matrix(i, j), 2);
            }
        }
    }
}

//Individual task realisation for fractions
template<> void elemConversion(Matrix<Fraction>& matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            //fraction value:
            double temp = static_cast<double>(matrix(i, j).getNumerator()) / static_cast<double>(matrix(i, j).getDenominator());
            if (std::floor(temp) == temp && static_cast<int>(temp) % 2 == 0) {
                matrix(i, j) = matrix(i, j) * matrix(i, j);
            }
        }
    }
}

//Template function for finding the minimum element among the elements of the matrix
template<typename someType> someType findMinValue(Matrix<someType> &matrix) {
    someType min = matrix(0, 0);
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            if (matrix(i, j) < min) {
                min = matrix(i, j);
            }
        }
    }
    return min;
}

int main()
{
    //Testing exception InvalidMatrixSize
    try {
        cout << "Creating a int matrix with size of 3x(-2)...\n";
        Matrix<int> matrix_test(3, -2);
    }
    catch (const Matrix<int>::InvalidMatrixSize& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    cout << endl;

    cout << "Creating a double matrix 1 with size of 3x2\n";
    Matrix<double> matrix1(3, 2);
    cout << "Enter double values for matrix 1:\n";
    cin >> matrix1;
    cout << endl;

    cout << "The minimum value of double matrix 1: " << findMinValue(matrix1) << "\n\n";

    //Individual task
    cout << "Performing an individual task for matrix 1...\n";
    elemConversion(matrix1);
    cout << "Matrix 1:\n";
    cout << matrix1;
    cout << endl;

    cout << "Creating a double matrix 2 with size of 3x2\n";
    Matrix<double> matrix2(3, 2);
    cout << "Enter other double values for matrix 2:\n";
    cin >> matrix2;
    cout << endl;

    cout << "Creating a double matrix 3 with size of 2x3\n";
    Matrix<double> matrix3(2, 3);
    cout << "Enter double values for matrix 3:\n";
    cin >> matrix3;

    cout << endl;

    //Testing exception IndexOutOfRange
    try {
        cout << "Refer to the element[4][5] of matrix 3...\n";
        matrix3(4, 5);
    }
    catch (const Matrix<double>::IndexOutOfRange& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    cout << endl;

    //Testing the addition operation(double)
    cout << "matrix 1 + matrix 2:\n";
    cout << matrix1 + matrix2 << endl;

    //Testing the subtraction operation(double)
    cout << "matrix 1 - matrix 2:\n";
    cout << matrix1 - matrix2 << endl;

    //Testing the product operation(double)
    cout << "matrix 1 * matrix 3:\n";
    Matrix<double> matrix_multiplication_1_3 = matrix1 * matrix3; //using copy constructor
    cout << matrix_multiplication_1_3 << endl;

    //Testing exception SizeMismatchException
    try {
        cout << "matrix 1 * matrix 2:\n";
        cout << matrix1 * matrix2 << endl;
    }
    catch (const Matrix<double>::SizeMismatchException& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    //Individual task
    cout << endl;
    cout << "Creating a int matrix 4 with size of 4x4\n";
    Matrix<int> matrix4(4, 4);
    cout << "Enter integer values for matrix 4:\n";
    cin >> matrix4;
    cout << endl;

    cout << "The minimum value of int matrix 4: " << findMinValue(matrix4) << "\n\n";

    cout << "Performing an individual task for matrix 4...\n";
    elemConversion(matrix4);
    cout << "Matrix 4:\n";
    cout << matrix4;
    cout << endl;

    cout << "Creating a matrix 5 with fractions with size of 2x2...\n";
    Matrix<Fraction> matrix5(2, 2);
    matrix5(0, 0) = Fraction(2, 5);
    matrix5(0, 1) = Fraction(2, 5);
    matrix5(1, 0) = Fraction(-2, 5);
    matrix5(1, 1) = Fraction(2, 5);

    cout << "Matrix 5:\n";
    cout << matrix5;

    cout << "The minimum value of matrix 5 with fractions: " << findMinValue(matrix5) << "\n\n";

    cout << "Creating a matrix 6 with fractions with size of 2x2...\n";
    Matrix<Fraction> matrix6(2, 2);
    matrix6(0, 0) = Fraction(1, 10);
    matrix6(0, 1) = Fraction(-3, 10);
    matrix6(1, 0) = Fraction(-2, 5);
    matrix6(1, 1) = Fraction(3, 10);

    cout << "Matrix 6:\n";
    cout << matrix6;
    cout << endl;

    //Testing the addition operation(fractions)
    cout << "matrix 5 + matrix 6:\n";
    cout << matrix5 + matrix6 << endl;

    //Testing the subtraction operation(fractions)
    cout << "matrix 5 - matrix 6:\n";
    cout << matrix5 - matrix6 << endl;

    //Testing the product operation(fractions)
    cout << "matrix 5 * matrix 6:\n";
    Matrix<Fraction> matrix_multiplication_5_6 = matrix5 * matrix6; //using copy constructor
    cout << matrix_multiplication_5_6 << endl;

    //Testing exception DevisionByZero
    try {
        cout << "Creating a fraction 10/0 ...\n";
        Fraction fractionTest(10, 0);
    }
    catch(const Fraction::DevisionByZero & e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "Creating a matrix 7 with fractions with size of 2x2...\n";
    Matrix<Fraction> matrix7(2, 2);
    matrix7(0, 0) = Fraction(10, 5);
    matrix7(0, 1) = Fraction(2, 5);
    matrix7(1, 0) = Fraction(-10, 5);
    matrix7(1, 1) = Fraction(4, 7);

    cout << "Matrix 7:\n";
    cout << matrix7; 
    
    //Individual task
    cout << "Performing an individual task for matrix 5...\n";
    elemConversion(matrix7);
    cout << "Matrix 7:\n";
    cout << matrix7;
    cout << endl;

    return 0;
}