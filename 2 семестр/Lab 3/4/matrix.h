#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <exception>
#include "fraction.h"

using std::istream;
using std::ostream;
using std::exception;
using std::cout;
using std::cin;
using std::endl;

//A generic class for representing a two-dimensional array
template<typename someType>
class Matrix {
    //Overloaded output operation on a stream
    friend ostream& operator<<(ostream& out, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                out << matrix.data[i][j] << "\t";
            }
            out << "\n";
        }
        return out;
    }
    //Overloaded input operation 
    friend istream& operator>>(istream& in, Matrix& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                in >> matrix.data[i][j];
            }
        }
        return in;
    }
private:
    someType** data = nullptr;
    int rows = 0;
    int cols = 0;
public:
    //Exception class to handle errors related to matrix index exceeding its dimensions
    class IndexOutOfRange : public exception {
    public:
        virtual const char* what() const noexcept { //the function cannot throw exceptions
            return "Matrix index out of range";
        }
    };

    //Exception class for matrix sizes
    class InvalidMatrixSize : public exception {
    public:
        virtual const char* what() const noexcept { //the function cannot throw exceptions
            return "Invalid matrix size";
        }
    };

    //Exception class to handle errors related to matrix size mismatch in operations
    class SizeMismatchException : public exception {
    public:
        virtual const char* what() const noexcept { //the function cannot throw exceptions
            return "Size Mismatch Exception";
        }
    };
    //Constrcuctors:
    //The constructor without parameters:
    Matrix() {}
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);

    //Destructor
    ~Matrix();

    //Getters:
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    //Overload the operation of a function call 
    someType& operator()(int row, int col);
    //Overloading operations + , -, *
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

};

//The constructor with 2 parameters
template<typename someType> Matrix<someType>::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    if (rows <= 0 || cols <= 0) {
        throw InvalidMatrixSize();
    }
    data = new someType* [rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new someType[cols];
    }
}

//Copy constructor
template<typename someType> Matrix<someType>::Matrix(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;
    data = new someType* [rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new someType[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

template<typename someType> Matrix<someType>::~Matrix() {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
}

//Matrix element access operator
template<typename someType> someType& Matrix<someType>::operator()(int row, int col) {
    if (row >= rows || col >= cols || row < 0 || col < 0) {
        throw IndexOutOfRange();
    }
    return data[row][col];
}

//Overloading operation +
template<typename someType> Matrix<someType> Matrix<someType>::operator+(const Matrix<someType>& other) const {
    //Checking that the matrix sizes are appropriate for their addition
    if (rows != other.rows || cols != other.cols) {
        throw SizeMismatchException();
    }
    Matrix<someType> result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return result;
}

//Overloading operations -
template<typename someType> Matrix<someType> Matrix<someType>::operator-(const Matrix<someType>& other) const {
    //Checking that the matrix sizes are appropriate for their subtraction
    if (rows != other.rows || cols != other.cols) {
        throw SizeMismatchException();
    }
    Matrix<someType> result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }
    return result;
}

//Overloading operations *
template<typename someType> Matrix<someType> Matrix<someType>::operator*(const Matrix<someType>& other) const {
    //Checking that the matrix sizes are appropriate for their multiplication
    if (rows != other.cols || cols != other.rows) {
        throw SizeMismatchException();
    }
    Matrix<someType> result(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            someType sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += data[i][k] * other.data[k][j]; //cols = other.rows
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

//Overloading operations * for Matrix<Fraction>
template<> Matrix<Fraction> Matrix<Fraction>::operator*(const Matrix<Fraction>& other) const {
    //Checking that the matrix sizes are appropriate for their multiplication
    if (rows != other.cols || cols != other.rows) {
        throw SizeMismatchException();
    }
    Matrix<Fraction> result(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            Fraction sum;
            for (int k = 0; k < cols; k++) {
                Fraction temp = data[i][k] * other.data[k][j];
                sum = sum + temp; //cols = other.rows
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}


#endif
