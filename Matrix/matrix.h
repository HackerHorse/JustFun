#ifndef __MATRIX__
#define __MATRIX__

int **decl_matrix(int row, int col);
int read_matrix(int **matrix, int row, int col);
void write_matrix(int **matrix, int row, int col, int data);
void destroy_matrix(int **matrix);

#endif
