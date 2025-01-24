// CODE: include necessary library(s)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function to generate a random matrix
void generateMatrix(int rows, int cols, double matrix[rows][cols]) {
    // give a random value to every entry
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            // (double)rand()/RAND_MAX generate a double value between 0 and 1
            // mutiply 20 and then - 10 to generate a number between -10 and 10
            matrix[i][j] = ((double)rand() / RAND_MAX) * 20 - 10;
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, double matrix[rows][cols]) {
    // print my matrixxxxxxxxxxx!
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            // print out with the specific format

            // for negative entries, we don't need a space before number
            if (matrix[i][j] < 0){
                printf("%f ", matrix[i][j]);
            }

            // for positive entries, we need a space before number
            else{
                printf(" %f ", matrix[i][j]);
            }
        }
        // switch the line
        printf("\n");
    } 
}

// Function to add two matrices
void addMatrices(int rows1, int cols1, double A[rows1][cols1], int rows2, int cols2, double B[rows2][cols2], double result[rows1][cols1]) {
    // check if the size of the matrices are legal
    if (rows1 != rows2 || cols1 != cols2){
        return;
    }
    
    else{
        for (int i = 0; i < rows1; i++){
            for (int j = 0; j < cols1; j++){
                // adding entries
                result[i][j] = A[i][j] + B[i][j];
            }
        }
    }
}

void subtractMatrices(int rows1, int cols1, double A[rows1][cols1], int rows2, int cols2, double B[rows2][cols2], double result[rows1][cols1]) {
    // check if the size of matrices are legal
    if (rows1 != rows2 || cols1 != cols2){
        return;
    }
    
    else{
        for (int i = 0; i < rows1; i++){
            for (int j = 0; j < cols1; j++){
                // subtracting entries
                result[i][j] = A[i][j] - B[i][j];
            }
        }
    }   
}

void multiplyMatrices(int rows1, int cols1, double A[rows1][cols1], int rows2, int cols2, double B[rows2][cols2], double result[rows1][cols2]) {
    // check if the size of matrices are legal
    if (cols1 != rows2){
        return;
    }
    
    else{
        for (int i = 0; i < rows1; i++){
            for (int j = 0; j < cols2; j++){
                // mutiplication procedure
                for (int k = 0; k < cols1; k++){
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }   
}

void solveLinearSystem(int rows1, int cols1, double A[rows1][cols1], int rows2, int cols2, double B[rows2][cols2], double result[rows1][cols2]) {
    // check if the size of matrices are legal
    if (rows1 != cols1){
        return;
    }
    
    // B needs to be a n x 1 matrix
    if (rows2 != rows1 || cols2 != 1){
        return;
    }

    // Gaussian elimination

    // we don't need to do Gaussian elimination (cause after all operations, the last row is already perfect) for entries in the last row, so end before the last row
    for (int i = 0; i < rows1 - 1; i++){
        // for all rows below the ith row, we do some operations to them         
        for (int j = i + 1; j < rows1; j++) {
            // make it a upper triangular matrix
            double factor = A[j][i] / A[i][i];
            for (int k = i; k < cols1; k++) {
                A[j][k] -= factor * A[i][k];
            }
            B[j][0] -= factor * B[i][0];
        }
    }

    for (int i = 0; i < rows1; i++){
        if (A[i][i] == 0){
            printf("ERROR! This Matrix is a singular matrix! Unsolvable!\n");
            return;
        }
    }

    // Back substitution
    for (int i = rows1 - 1; i >= 0; i--) {
        result[i][0] = B[i][0];
        for (int j = i + 1; j < cols1; j++) {
            result[i][0] -= A[i][j] * result[j][0];
        }
        result[i][0] /= A[i][i];
    }
}