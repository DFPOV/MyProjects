// Code: Here include your necessary library(s)
// Code: Write your global variables here, like: #define N 9
/* Code: write your functions here, or the declaration of the function
For example write the recursive function solveSudoku(), like: */
#include <stdio.h>
#include <stdbool.h>

int SDG[9][9] = {
    {5, 3, 1, 0, 7, 0, 0, 0, 0},
    {6, 0, 2, 1, 9, 5, 0, 0, 0},
    {0, 1, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

int count = 0;

// Code: count+1, the number of times the function was called.
// Code: here write the implementation of solveSudoku

bool check_if_valid(int num, int row, int col);

int solveSudoku(int row, int col);

void printSudoku();

int main() {
    printf("The input Sudoku puzzle:\n");

    printSudoku();

    int result = solveSudoku(0, 0);
    
    if (result == 0) {
        // If the puzzle is solved then:
        printf("Solution found after %d iterations:\n", count);
        printSudoku(SDG);
    } else {
        printf("\n\nNo solution exists!");
    }

    return 0;
}
/* Code: If you have functions that are declared but not implemented
they, here write the implementation. */

bool check_if_valid(int row, int col, int num){
    for (int j = 0; j < 9; j++){
        if (SDG[row][j] == num){
            return false;
        }
    }

    for (int i = 0; i < 9; i++){
        if (SDG[i][col] == num){
            return false;
        }
    }

    int g_col, g_row;
    
    switch (row){
        case 0:
        case 1:
        case 2:
            g_row = 0;
            break;

        case 3:
        case 4:
        case 5:
            g_row = 3;
            break;

        case 6:
        case 7:
        case 8:
            g_row = 6;
            break;

        default:
            g_row = 0;
    }

    switch (col){
        case 0:
        case 1:
        case 2:
            g_col = 0;
            break;

        case 3:
        case 4:
        case 5:
            g_col = 3;
            break;

        case 6:
        case 7:
        case 8:
            g_col = 6;
            break;

        default:
            g_col = 0;
    }

    for (int i = g_row; i < (g_row + 3); i++){
        for (int j = g_col; j < (g_col + 3); j++){
            if (SDG[i][j] == num){
               return false;
            }
        }
    }
    return true;
}

int solveSudoku(int row, int col) {
    // find first empty place
    count += 1;
    int found = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (SDG[i][j] == 0) {
                found = 1; // found!
                bool Possible_Num[9] = {};

                for (int k = 0; k < 9; k++) {
                    Possible_Num[k] = check_if_valid(i, j, k + 1);
                }

                for (int f = 0; f < 9; f++) {
                    if (Possible_Num[f]) {
                        SDG[i][j] = f + 1;
                        if (solveSudoku(i, j + 1) != -1) { // try next
                            count -= 1;
                            return 0; // found the solution
                        }
                        SDG[i][j] = 0; // backtracking
                    }
                }
                return -1; // fall back!
            }
        }
    }

    if (!found) {
        return 0; // we did it
    }

    // default
    return -1;
}

void printSudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", SDG[i][j]);
            if (j == 2 || j == 5) {
                printf("| ");
            }
        }
        printf("\n");
        if (i == 2 || i == 5) {
            printf("-----------------------\n");
        }
    }
}