#ifndef TABLE_H
#define TABLE_H

typedef struct Table Table;

Table *table_new(int rows, int columns, int column_width);

void drop_table(Table **table);

int read_cell(Table *table, int row, int column);

#endif