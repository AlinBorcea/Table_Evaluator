#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#include "table.h"

#define BUFFER_SIZE 32
#define CLS() system("cls")

enum InputOption {
    EXIT,
    MENU,
    SEL,
    PRINT,
    READ,
    CLS,
};

void print_menu() {
    printf("exit -> 0\n");
    printf("menu -> 1\n");
    printf("sel -> 2 [row] [column]\n");
    printf("print -> 3\n");
    printf("read -> 4\n");
    printf("clear -> 5\n");
}

void run_main_loop(Table *table) {
    int option = MENU;
    int row = 0;
    int col = 0;
    int err = 0;
    
    while (option != EXIT) {
        switch (option) {
            case EXIT: 
                break;

            case MENU: 
                print_menu(); 
                break;

            case SEL:
                printf("row = "); scanf("%d", &row);
                printf("col = "); scanf("%d", &col);
                break;

            case PRINT:
                print_lengths(table);
                break;

            case READ: 
                err = read_cell(table, row, col);
                break;

            case CLS:
                CLS();
                break;

            default: 
                printf("no option %d\n", option); 
                break;
        }

        if (err != 0) {
            printf("error\n");
        }

        printf("read option\n");
        option = getch() - 48;
    }

    CLS();
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("too few args\n");
        return 1;
    }

    int rows = atoi(argv[1]);
    int columns = atoi(argv[2]);
    int width = atoi(argv[3]);

    if (rows <= 0 || columns <= 0 || width <= 0) {
        printf("args are integers gt 0\n");
        return 1;
    }

    Table *table = table_new(rows, columns, width);
    if (!table) {
        printf("table is null");
        return 1;
    }

    run_main_loop(table);
    drop_table(&table);
    return 0;
}