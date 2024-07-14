//Class for representing a two-dimensional array
#include <iostream>
#include <exception>
#include <vector>

using std::vector;
using std::istream;
using std::ostream;
using std::exception;
using std::cout;
using std::cin;
using std::endl;

class Matrix {
    //Overloaded output operation on a stream
    friend ostream& operator<<(ostream& out, const Matrix& matrix);
    //Overloaded input operation 
    friend istream& operator>>(istream& in, Matrix& matrix);
private:
    vector<vector<int>> data;
public:
    //Exception class to handle errors related to matrix index exceeding its dimensions
    class IndexOutOfRange : public exception {
        virtual const char* what() const throw() {
            return "Matrix index out of range";
        }
    };

    //Exception class for matrix sizes
    class InvalidMatrixSize : public exception {
        virtual const char* what() const throw() {
            return "Invalid matrix size";
        }
    };

    //Exception class to handle errors related to matrix size mismatch in operations
    class SizeMismatchException : public exception {
    public:
        virtual const char* what() const throw() {
            return "Size Mismatch Exception";
        }
    };
    //Constrcuctors:
    //The constructor without parameters:
    Matrix() {}
    Matrix(int rows, int cols);

    //Getters:
    int getRows() const { return data.size(); }
    int getCols() const { 
        if (data.empty())
            return 0;
        return data[0].size(); 
    }

    //Overload the operation of a function call 
    int& operator()(int row, int col);
    //Overloading operations + , -, *
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

};

//The constructor with 2 parameters
Matrix::Matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        throw InvalidMatrixSize();
    }
    data = vector<vector<int>>(rows, vector<int>(cols));
}

//Matrix element access operator
int& Matrix::operator()(int row, int col) {
    if (row >= getRows() || col >= getCols() || row < 0 || col < 0) {
        throw IndexOutOfRange();
    }
    return data[row][col];
}

//Overloading operation +
Matrix Matrix::operator+(const Matrix& other) const {
    //Checking that the matrix sizes are appropriate for their addition
    if (getRows() != other.getRows() || getCols() != other.getCols()) {
        throw SizeMismatchException();
    }
    Matrix result(getRows(), getCols());
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getCols(); j++) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return result;
}

//Overloading operations -
Matrix Matrix::operator-(const Matrix& other) const {
    //Checking that the matrix sizes are appropriate for their subtraction
    if (getRows() != other.getRows() || getCols() != other.getCols()) {
        throw SizeMismatchException();
    }
    Matrix result(getRows(), getCols());
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getCols(); j++) {
            result.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }
    return result;
}

//Overloading operations *
Matrix Matrix::operator*(const Matrix& other) const {
    //Checking that the matrix sizes are appropriate for their multiplication
    if (getRows() != other.getCols() || getCols() != other.getRows()) {
        throw SizeMismatchException();
    }
    Matrix result(getRows(), other.getCols());
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < other.getCols(); j++) {
            int sum = 0;
            for (int k = 0; k < getCols(); k++) {
                sum += data[i][k] * other.data[k][j]; //cols = other.rows
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

istream& operator>>(istream& in, Matrix& matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            in >> matrix.data[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const Matrix& matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            out << matrix.data[i][j] << "\t";
        }
        out << "\n";
    }
    return out;
}

//Individual task realisation
void elemConversion(Matrix& matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            if (matrix(i, j) % 2 == 0) {
                matrix(i, j) = pow(matrix(i, j), 2);
            }
        }
    }
}

int main()
{
    //Testing exception InvalidMatrixSize
    try {
        cout << "Creating a matrix with size of 3x(-2)...\n";
        Matrix matrix_test(3, -2);
    }
    catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    cout << endl;

    cout << "Creating a matrix 1 with size of 3x2\n";
    Matrix matrix1(3, 2);
    cout << "Enter values for matrix 1:\n";
    cin >> matrix1;
    cout << endl;

    cout << "Creating a matrix 2 with size of 3x2\n";
    Matrix matrix2(3, 2);
    cout << "Enter other values for matrix 2:\n";
    cin >> matrix2;
    cout << endl;

    cout << "Creating a matrix 3 with size of 2x3\n";
    Matrix matrix3(2, 3);
    cout << "Enter values for matrix 3:\n";
    cin >> matrix3;

    cout << endl;

    //Testing exception IndexOutOfRange
    try {
        cout << "Refer to the element[4][5] of matrix 3...\n";
        matrix3(4, 5);
    }
    catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    cout << endl;

    //Testing the addition operation
    cout << "matrix 1 + matrix 2:\n";
    cout << matrix1 + matrix2 << endl;

    //Testing the subtraction operation
    cout << "matrix 1 - matrix 2:\n";
    cout << matrix1 - matrix2 << endl;

    //Testing the product operation
    cout << "matrix 1 * matrix 3:\n";
    Matrix matrix_multiplication_1_3 = matrix1 * matrix3; //using copy constructor
    cout << matrix_multiplication_1_3 << endl;

    //Testing exception SizeMismatchException
    try {
        cout << "matrix 1 * matrix 2:\n";
        cout << matrix1 * matrix2 << endl;
    }
    catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    //Individual task
    cout << endl;
    cout << "Creating a matrix 4 with size of 4x4\n";
    Matrix matrix4(4, 4);
    cout << "Enter values for matrix 4:\n";
    cin >> matrix4;
    cout << endl;
    cout << "Performing an individual task for matrix 4...\n";
    elemConversion(matrix4);
    cout << "Matrix 4:\n";
    cout << matrix4;

    return 0;
}
