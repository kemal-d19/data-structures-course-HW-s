#include "matrix.h"
#include <iostream>

using namespace std;

// Constructor to create a matrix of given dimensions
Matrix::Matrix(int row, int col) {
    rows  = row;
    cols = col;
    data = new double*[rows];
    for(int i = 0; i < rows; i++){
        data[i] = new double[cols];
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            data[i][j] = 0;
        }
    };
}

// Copy constructor
Matrix::Matrix(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;
    double** data;
    data = new double*[rows];
        for(int i = 0; i < rows; i++){
        data[i] = new double[cols];
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            data[i][j] = other.data[i][j];
        }
    } 
}

// Destructor to deallocate memory
Matrix::~Matrix() {
    for(int i = 0; i < rows; i++){
        delete[] data[i];
    }
    delete[] data;
}

// Function to reshape the matrix
void Matrix::reshape(int newRows, int newCols) {
    if (newRows * newCols == 0 || (newRows < 0 && newCols < 0)){
        cout << "Cannot perform reshape because both dimensions are invalid." << endl;
    }
    else if  (((newRows==-1 || newCols==-1) && (rows * cols) % (newRows * newCols) != 0) || ((newRows!=-1 && newCols!=-1) && (newRows*newCols != rows*cols))){
        cout << "Cannot perform reshape because dimensions are not compatible." << endl;
    }
    else {
        int newR, newC;
        newR = (newRows == -1) ? (rows * cols) / newCols : newRows;
        newC = (newCols == -1) ? (rows * cols) / newRows : newCols;
        double** new_data = new double*[newR];
        for(int i = 0; i < newR; i++){
            new_data[i] = new double[newC];
        }
        int mul;
        for(int i = 0; i < newR; i++){
            for(int j = 0; j < newC; j++){
                mul = (i * (newC)) + j;
                new_data[i][j] = data[(int)(mul/cols)][mul%(cols)];
            }
        }

        for(int i = 0; i < rows; i++){
            delete[] data[i];
        } 
        rows = newR;
        cols = newC;
        data = new_data;
    }
}

// Function to multiply two matrices
Matrix Matrix::multiply(const Matrix& other) const {
    Matrix result(rows,other.cols);
    if (cols != other.rows){
            cout << "Cannot multiply matrices: incompatible dimensions." << endl;
    }
    else {
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < other.cols; j++){
                double sum = 0;
                for(int k = 0; k < cols; k++){
                    sum += data[i][k] * other.data[k][j];
                }
                result.set(i, j, sum);
            }
        
        }
    }
    return result;  
}

// Function to flatten the matrix into a 1D array
double* Matrix::flatten() const {
    double* flat_array = new double[rows * cols];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            flat_array[(i * cols) + j] = data[i][j];
        }
    }
    return flat_array; 
}

// Function to apply a filter to the matrix
Matrix Matrix::applyFilter(const Matrix& filter) const {
    int result_row = rows - filter.rows + 1;
    int result_col = cols - filter.cols + 1;
    Matrix filtered(result_row, result_col);
    for(int i = 0; i < result_row; i++){
        for(int j = 0; j < result_col; j++){
            double sum = 0;
            for(int k = 0; k < filter.rows; k++){
                for(int m = 0; m < filter.cols; m++){
                    sum += data[i+k][j+m] * filter.get(k,m);
                }
            }

            filtered.set(i, j, sum);
        }
    }
    return filtered;
}

// Function to get an element at (x, y)
double Matrix::get(int x, int y) const {
    return data[x][y];
}

// Function to set an element at (x, y)
void Matrix::set(int x, int y, double value) {
    data[x][y] = value; 
}

// Function to transpose the matrix
Matrix Matrix::transpose() const {
    Matrix transpose(cols, rows);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            transpose.set(j, i, data[i][j]);
        }
    }
    return transpose;
}

// Function to print the matrix
void Matrix::print() const {
    for(int i = 0; i < rows;i++){
        for(int j = 0; j < cols; j++){
            if (j != 0){cout << " ";}
            cout << fixed << setprecision(3) << data[i][j];
        }
        cout << endl; 
    }
}