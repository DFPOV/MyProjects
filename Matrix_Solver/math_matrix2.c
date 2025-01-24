#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));

    // Check if the number of arguments is correct
    if (argc < 6 || argc > 7) {
        printf("Usage: %s nN1_A nM1_A nN1_B nM1_B <operation> [print]\n", argv[0]);
        return 1;
    }

    // CODE: Generate random matrices A with size N1*M1 and B with size N2*M2
    int N1 = atoi(argv[1]);
    int M1 = atoi(argv[2]);
    int N2 = atoi(argv[3]);
    int M2 = atoi(argv[4]);
    char *operation = argv[5];
    int print = (argc == 7 && strcmp(argv[6], "print") == 0);

    double A[N1][M1], B[N2][M2], result[N1][M1], result_multiply[N1][M2], x[N1][M2];

    generateMatrix(N1, M1, A);
    generateMatrix(N2, M2, B);
    // CODE: call the functions as needed
    

    if (strcmp(operation, "add") == 0) {
        addMatrices(N1, M1, A, N2, M2, B, result);
    } else if (strcmp(operation, "subtract") == 0) {
        subtractMatrices(N1, M1, A, N2, M2, B, result);
    } else if (strcmp(operation, "multiply") == 0) {
        multiplyMatrices(N1, M1, A, N2, M2, B, result_multiply);
        if (print) {
            printf("Matrix A:\n");
            printMatrix(N1, M1, A);
            printf("\nMatrix B:\n");
            printMatrix(N2, M2, B);
            printf("\nResult:\n");
            printMatrix(N1, M2, result_multiply);
        }
        return 0;
    } 
    else if (strcmp(operation, "solve") == 0) {
        printf("Matrix A:\n");
        printMatrix(N1, M1, A);
        printf("\nMatrix B:\n");
        printMatrix(N2, M2, B);
        solveLinearSystem(N1, M1, A, N2, M2, B, x);
        printf("Solution vector x:\n");
        printMatrix(N1, M2, x);
        return 0;
    } 
    else {
        printf("Invalid operation.\n");
        return 1;
    }

    if (print) {
        printf("Matrix A:\n");
        printMatrix(N1, M1, A);
        printf("\nMatrix B:\n");
        printMatrix(N2, M2, B);
        printf("\nResult:\n");
    }
    return 0;
}