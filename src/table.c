#include "table.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct Cell {
    char *content;
} Cell;

struct Table {
    int rows;
    int columns;
    int column_width;
    Cell *cells;
};

Cell *create_cells(int rows, int columns, int column_width) {
    Cell *cells = (Cell*) malloc(rows * columns * sizeof(Cell));
    if (!cells) return NULL;

    for (int i = 0; i < rows * columns; i++) {
        cells[i].content = (char*) calloc(column_width, sizeof(char));
        if (!cells[i].content) {
            i--;
            while (i >= 0) {
                free(cells[i].content);
                i--;
            }
            return NULL;
        }
    }

    return cells;
}

//Table
Table *table_new(int rows, int columns, int column_width) {
    if (rows <= 0 || columns <= 0 || column_width <= 0) {
        return NULL;
    }

    Table *table = (Table*) malloc(sizeof(Table));
    if (!table) return NULL;

    (*table).rows = rows;
    (*table).columns = columns;
    (*table).column_width = column_width;
    (*table).cells = create_cells(rows, columns, column_width);
    
    if (!(*table).cells) {
        free(table);
        return NULL;
    }

    return table;
}

void drop_table(Table **table) {
    int rows = (*(*table)).rows;
    int columns = (*(*table)).columns;
    Cell *cells = (*(*table)).cells;

    for (int i = 0; i < rows * columns; i++) {
        free(cells[i].content);  
    }

    free(cells);
    free(*table);
    *table = NULL;
}

int read_cell(Table *table, int row, int column) {
    char ch = '0';
    int i = 0;

    if (row >= (*table).rows || column >= (*table).columns) return 1;

    Cell *cell = (*table).cells + row * (*table).columns + column;
    while (i < (*table).column_width - 1) {
        ch = getch();
        if (ch == '\r') break;

        printf("%c", ch);
        (*cell).content[i] = (char) ch;
        i++;
    }

    printf("\n");
    (*cell).content[i] = '\0';
    return 0;
}

char *get_cell_content(Table *table, int row, int column) {
    if (row >= (*table).rows || column >= (*table).columns) return NULL;

    return (*table).cells[row * (*table).columns + column].content;
}

void print_lengths(Table *table) {
    for (int i = 0; i < (*table).rows * (*table).columns; i++) {
        printf("%d ", strlen((*table).cells[i].content));
    }
}