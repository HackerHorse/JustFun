#include <stdio.h>

#include "matrix.h"

int main()
{
	int **matrix;
	int row = 20;
	int col = 20;
	int i,j;
	int read_row = 10;
	int read_col = 15;
	matrix = decl_matrix(row, col);

	printf("Matrix Read:%d\n", read_matrix(matrix, read_row, read_col));
	write_matrix(matrix, read_row, read_col, 1);
	printf("After Matrix Read:%d\n", read_matrix(matrix, read_row, read_col));

	for(i = 0; i< row; i++) {
		for(j = 0; j < col; j++) {
			printf(" %d(%d/%d) ", read_matrix(matrix, i, j), i, j);
		}
		printf("\n");
	}
	destroy_matrix(matrix);
	return 0;
}
