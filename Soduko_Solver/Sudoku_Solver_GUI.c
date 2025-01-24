#include <gtk/gtk.h>
#include <stdio.h>
#include <stdbool.h>

int SDG[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
}; // initialize the grid at the begining 


// declaration before use

int SDG2[9][9] = {};

int count = 0;

bool check_if_valid(int num, int row, int col);

int solveSudoku(int row, int col);

void printSudoku();

void S_sudoku();

void R_sudoku();

void change_entry_text_color(GtkWidget* entry, const gchar* color);

GtkWidget *entries[9][9];

GtkWidget *message_label;

int main(int argc, char *argv[]) {
    // initialize SDG2 with SDG (too lazy to create a new one)
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            SDG2[i][j] = SDG[i][j];
        }
    }

    // initialize gtk, passing command line arguments to allow GTK to parse them.
    gtk_init(&argc, &argv);

    // set the size and create window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Sudoku Solver");
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 450, 500);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // initialize the size of entries and numbers of entries with SDG
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            entries[i][j] = gtk_entry_new();
            gtk_entry_set_max_length(GTK_ENTRY(entries[i][j]), 1);
            gtk_grid_attach(GTK_GRID(grid), entries[i][j], j, i+1, 1, 1);
            gtk_widget_set_size_request(entries[i][j], 50, 50);

            if (SDG[i][j] != 0) {
                char numStr[2]; 
                sprintf(numStr, "%d", SDG[i][j]);
                gtk_entry_set_text(GTK_ENTRY(entries[i][j]), numStr);
            }
        }
    }

    // add and set positions of two buttons and a message

    GtkWidget *resetButton = gtk_button_new_with_label("Reset");
    g_signal_connect(resetButton, "clicked", G_CALLBACK(R_sudoku), NULL);
    
    gtk_grid_attach(GTK_GRID(grid), resetButton, 0, 10, 9, 1);

    GtkWidget *solveButton = gtk_button_new_with_label("Solve");
    g_signal_connect(solveButton, "clicked", G_CALLBACK(S_sudoku), NULL);

    gtk_grid_attach(GTK_GRID(grid), solveButton, 0, 11, 9, 1);

    message_label = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), message_label, 0, 0, 9, 1);
    
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_set_size_request(resetButton, 100, 50);
    gtk_widget_set_size_request(solveButton, 100, 50);
    gtk_widget_set_size_request(message_label, 100, 50);


    gtk_widget_show_all(window);

    // start the loop of gtk 
    gtk_main();

    return 0;
}

// check if the filling of a number is valid or not
bool check_if_valid(int row, int col, int num){
    // check the row
    for (int j = 0; j < 9; j++){
        if (SDG[row][j] == num){
            return false;
        }
    }

    // check the column
    for (int i = 0; i < 9; i++){
        if (SDG[i][col] == num){
            return false;
        }
    }

    int g_col, g_row;
    
    // check the 3x3 area
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

    // default return
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
        return 0; // we did it!
    }

    // default return, in case of error happen
    return -1;
}

void S_sudoku(GtkWidget *widget, gpointer data) {

    // using entries to update SDG
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            const char* entry_text = gtk_entry_get_text(GTK_ENTRY(entries[i][j]));
            if (entry_text[0] == '\0') { // Empty cell
                SDG[i][j] = 0;
            } else {
                SDG[i][j] = atoi(entry_text);
            }
        }
    }

    // update SDG2 with SDG after the update of SDG
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            SDG2[i][j] = SDG[i][j];
        }
    }

    
    // running solver, if caused error then print no solutions
    if (solveSudoku(0, 0) == -1) {
        gtk_label_set_text(GTK_LABEL(message_label), "No Solution!");
        return;
    }else{
    // if successed, then print 
        gtk_label_set_text(GTK_LABEL(message_label), "Sudoku puzzle solved successfully!!!");
    }

    // using SDG2 to check what numbers need to be highlighted in red
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (SDG2[i][j] == 0 && SDG[i][j] != 0) {
                char numStr[2];
                sprintf(numStr, "%d", SDG[i][j]);
                gtk_entry_set_text(GTK_ENTRY(entries[i][j]), numStr);
                
                change_entry_text_color(entries[i][j], "#FF0000");
            }
        }
    }

    // and then update entries with SDG
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char numStr[2];
            sprintf(numStr, "%d", SDG[i][j]);
            gtk_entry_set_text(GTK_ENTRY(entries[i][j]), numStr);
        }
    }
}


void R_sudoku(GtkWidget *widget, gpointer data) {
    // clear all numbers, update SDG as well
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            gtk_entry_set_text(GTK_ENTRY(entries[i][j]), "");
            SDG[i][j] = 0;
            change_entry_text_color(entries[i][j], "#000000"); // make sure that all numbers are set back to black
        }
    }
}

void change_entry_text_color(GtkWidget *entry, const gchar *color) {
    // create a CSS provider
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gchar *css = g_strdup_printf("entry { color: %s; }", color);

    // load the CSS data to the provider
    gtk_css_provider_load_from_data(cssProvider, css, -1, NULL);

    // apply the CSS to the entry widget
    gtk_style_context_add_provider(gtk_widget_get_style_context(entry),
                                   GTK_STYLE_PROVIDER(cssProvider),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // cleanup support
    g_object_unref(cssProvider);
    g_free(css);
}

// used for normal version of solver, was not used in this GUI version 
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