#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function to generate a random matrix
void generateMatrix(int rows, int cols, double matrix[rows][cols]) {
    // CODE: Generate random numbers between -10 and 10
    srand(time(NULL)); 

    double min = -10.0;
    double max = 10.0;
    
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            matrix[r][c] = min + ((double)rand() / RAND_MAX) * (max - min);;
            printf("%8.2f", matrix[r][c]);
        }
        printf("\n");
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, double matrix[rows][cols]) {
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            printf("%8.2f", matrix[r][c]);
        }
        printf("\n");
    }
}
// Function to add two matrices
void addMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M1]){
    if(N1 != N2 || M1 != M2){
        printf("The size of matrices do not match. Please enter other indexes.");
    }

   for (int r = 0; r < N1; r++) {
        for (int c = 0; c < M1; c++) {
            result[r][c]=A[r][c] + B[r][c];
        }
    }
    for (int r = 0; r < N1; r++) {
        for (int c = 0; c < M1; c++) {
            printf("%8.2f ", result[r][c]);
        }
        printf("\n");
    }
}



// CODE: do the same for subtractMatrices, multiplyMatrices, and solveLinearSystem functions
void subtractMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M1]){
    if(N1 != N2 || M1 != M2){
        printf("The size of matrices do not match. Please enter other indexes.");
    }
    for (int r = 0; r < N1; r++){
        for (int c = 0; c < M1; c++) {
            result[r][c] = A[r][c] - B[r][c];
        }
    }
    
    for (int r = 0; r < N1; r++) {
        for (int c = 0; c < M1; c++) {
            printf("%8.2f ", result[r][c]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M2]){
    if(M1 != N2){
        printf("The size of matrices do not match. Please enter other indexes.");
    }
    for(int r=0; r < N1; r++){
        for(int c = 0; c < M2; c++){
            result[r][c] = 0;
            for(int k =0; k < M1; k++){
                result[r][c] += A[r][k]* B[k][c];
            }
        }
    }
     for (int r = 0; r < N1; r++) {
        for (int c = 0; c < M2; c++) {
            printf("%8.2f ", result[r][c]);
        }
        printf("\n");
    }
}

void solveLinearSystem(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double x[N1][M2]){
    for (int k = 0; k < N1; k++) {
        for (int i = k + 1; i < N1; i++) {
            double factor = A[i][k] / A[k][k];
            for (int j = k; j < M1; j++) {
                A[i][j] -= factor * A[k][j];
            }
            for (int j = 0; j < M2; j++) {
                B[i][j] -= factor * B[k][j];
            }
        }
    }

    for (int k = N1 - 1; k >= 0; k--) {
        for (int j = 0; j < M2; j++) {
            x[k][j] = B[k][j];
            for (int i = k + 1; i < N1; i++) {
                x[k][j] -= A[k][i] * x[i][j];
            }
            x[k][j] /= A[k][k];
        }
    }
    
    for (int r = 0; r < N1; r++) {
        for(int c = 0; c < M2; c++){
            printf("%8.2f", x[r][c]);
        }   
        printf("\n"); 
    }
}

