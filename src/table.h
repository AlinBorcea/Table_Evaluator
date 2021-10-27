#ifndef TABLE_H
#define TABLE_H

typedef struct Table Table;

Table *table_new(int rows, int columns, int column_width);

void drop_table(Table **table);

int read_cell(Table *table, int row, int column);

char *get_cell_content(Table *table, int row, int column);

void print_lengths(Table *table);

#endif