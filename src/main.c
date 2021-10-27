#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

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

void read_str(char input[BUFFER_SIZE]) {
    char ch = '0';
    int i = 0;

    while (i < BUFFER_SIZE - 1) {
        ch = getch();
        if (ch == '\r') break;

        printf("%c", ch);
        input[i] = (char) ch;
        i++;
    }

    printf("\n");
    input[i] = '\0';
}

void print_menu() {
    printf("exit -> 0\n");
    printf("menu -> 1\n");
    printf("sel -> 2 [row] [column]\n");
    printf("print -> 3\n");
    printf("read -> 4\n");
    printf("clear -> 5\n");
}

void run_main_loop() {
    char input[BUFFER_SIZE];
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
                read_str(input);
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
    run_main_loop();

    return 0;
}