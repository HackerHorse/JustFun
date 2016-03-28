#include <stdio.h>

#include "matrix.h"

int main()
{
	int **matrix;
	int row = 20;
	int col = 20;
	int i,j;
	int read_row = 4;
	int read_col = 5;

	matrix = decl_matrix(row, col);

	write_matrix(matrix, read_row, read_col, 1);
	write_matrix(matrix, read_col, read_row, 1);
	write_matrix(matrix, read_row, read_col, 1);

	for(i = 0; i< row; i++) {
		for(j = 0; j < col; j++) {
			printf(" %d ", read_matrix(matrix, i, j));
		}
		printf("\n");
	}
	destroy_matrix(matrix);
	return 0;
}
