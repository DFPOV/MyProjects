// CODE: include necessary library(s)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include <string.h>

int main(int argc, char *argv[]) {
    // set seed for randomizor
    srand(time(NULL));
    // get values from the input
    int rows1 = atoi(argv[1]);
    int cols1 = atoi(argv[2]);
    int rows2 = atoi(argv[3]);
    int cols2 = atoi(argv[4]);
    
    // matrices 
    double A[rows1][cols1];
    double B[rows2][cols2];
    double result[rows1][cols2];

    // initialize matrices
    generateMatrix(rows1, cols1, A);
    generateMatrix(rows2, cols2, B);
    
    // Check if the number of arguments is correct
    if (argc < 6 || argc > 7) {
        printf("Usage: %s nrows_A ncols_A nrows_B ncols_B <operation> [print]\n", argv[0]);
        return 1;
    }

    // Let's see which matchs the correct command
    if (argc == 7){
        // for addition
        if (strcmp(argv[5], "add") == 0 ){
            if (rows1 != rows2 || cols1 != cols2){
                printf("ERROR! The size of two matrices does not match the requirements for matrix addition!!!\n");
                return 1;
            }
            
            double result[rows1][cols1];
            addMatrices(rows1, cols1, A, rows2, cols2, B, result);
            
            if (strcmp(argv[6], "print") == 0){              
                // print all of them with the specific format
                printf("Matrix A: \n");
                printMatrix(rows1, cols1, A);
                printf("Matrix B: \n");
                printMatrix(rows2, cols2, B);
                printf("Result of A + B: \n");
                printMatrix(rows1, cols1, result);
            }
        }
        
        // for subtraction
        else if (strcmp(argv[5], "subtract") == 0 ){
            if (rows1 != rows2 || cols1 != cols2){
                printf("ERROR! The size of two matrices does not match the requirements for matrix subtraction!!!\n");
                return 1;
            }

            double result[rows1][cols1];
            subtractMatrices(rows1, cols1, A, rows2, cols2, B, result);
            
            if (strcmp(argv[6], "print") == 0){
                // print all of them with the specific format
                printf("Matrix A: \n");
                printMatrix(rows1, cols1, A);
                printf("Matrix B: \n");
                printMatrix(rows2, cols2, B);
                printf("Result of A - B: \n");
                printMatrix(rows1, cols1, result);
            }
        }
        
        // for multiplication
        else if (strcmp(argv[5], "multiply") == 0 ){
            if (cols1 != rows2){
                printf("ERROR! The size of two matrices does not match the requirements for matrix multiplication!!!\n");
                return 1;
            }

            double result[rows1][cols2];
            multiplyMatrices(rows1, cols1, A, rows1, cols2, B, result);
            
            if (strcmp(argv[6], "print") == 0){                    
                // print all of them with the specific format
                printf("Matrix A: \n");
                printMatrix(rows1, cols1, A);
                printf("Matrix B: \n");
                printMatrix(rows2, cols2, B);
                printf("Result of A * B: \n");
                printMatrix(rows2, cols2, result);
            }
        }

        // for solving the equation
        else if (strcmp(argv[5], "solve") == 0 ){
            if (rows1 != cols1){
                printf("ERROR! Matrix A must be square.\n");
                return 1;
            }
            
            else if (rows2 != rows1 || cols2 != 1){
                printf("ERROR! The size of matrix B is incorrect! \n");
                return 1;
            }
            
            double result[rows1][cols2];
            double A2[rows1][cols1];
            
            for (int i = 0; i < rows1; i++){
                for (int k = 0; k < cols1; k++){
                    A2[i][k] = A[i][k];
                }
            }

            solveLinearSystem(rows1, cols1, A, rows1, cols2, B, result);

            for (int i = 0; i < rows1; i++){
                if (A[i][i] == 0){
                    printf("ERROR! This Matrix is a singular matrix! Unsolvable!\n");
                    return 1;
                }
            }

            if (strcmp(argv[6], "print") == 0){
                // print all of them with the specific format
                printf("Matrix A: \n");
                printMatrix(rows1, cols1, A2);
                printf("Matrix B: \n");
                printMatrix(rows2, cols2, B);
                printf("Result of x=B/A : \n");
                printMatrix(rows2, cols2, result);
            }
        }

        else{
            return 0;
        }
    }
    
    return 0;
}