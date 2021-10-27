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

void run_main_loop() {
    //char input[BUFFER_SIZE];
    int option = MENU;
    
    while (option != EXIT) {
        switch (option) {
            case EXIT: 
                break;

            case MENU: 
                print_menu(); 
                break;

            case SEL: 
                break;

            case PRINT: 
                break;

            case READ: 
                //read_str(input);
                break;

            case CLS:
                CLS();
                break;

            default: 
                printf("no option %d\n", option); 
                break;
        }

        printf("read option\n");
        option = getch() - 48;
    }

    CLS();
}

int main() {
    //run_main_loop();
    int err = 0;

    Table *table = table_new(2, 3, 16);
    if (!table) {
        printf("table is null");
        return 1;
    }

    err = read_cell(table, 0, 0);
    if (err) {
        printf("error reading cell\n");
        return 1;
    }

    drop_table(&table);

    return 0;
}