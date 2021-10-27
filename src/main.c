#include <stdio.h>
#include <conio.h>
#include <string.h>

#define BUFFER_SIZE 32

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

int main() {
    char input[BUFFER_SIZE];

    read_str(input);
    int len = strlen(input);
    printf("str = %s len = %d\n", input, len);

    return 0;
}