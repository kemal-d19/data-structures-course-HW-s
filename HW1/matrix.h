#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip> // to set 3 digit precision for cout


class Matrix {
private:
    int rows; // Number of rows in the matrix
    int cols; // Number of columns in the matrix
    double** data; // Pointer to the matrix data

public:
    // Constructor to create a matrix of given dimensions
    Matrix(int rows, int cols);

    // Copy constructor
    Matrix(const Matrix& other);
    // Destructor to deallocate memory

    ~Matrix();
    // Function to reshape the matrix
    void reshape(int newRows, int newCols);

    // Function to multiply two matrices
    Matrix multiply(const Matrix& other) const;

    // Function to flatten the matrix into a 1D array
    double* flatten() const;
    
    // Function to apply a filter to the matrix
    Matrix applyFilter(const Matrix& filter) const;

    // Function to get an element at (x, y)
    double get(int x, int y) const;
    
    // Function to set an element at (x, y)
    void set(int x, int y, double value);

    // Function to transpose the matrix
    Matrix transpose() const;

    // Print the matrix
    // floating point numbers should be written in 3 digit precision
    void print() const;
};


#endif // MATRIX_H