#include <stdlib.h>

#include "matrix.h"
#include "bitmap.h"

int **decl_matrix(int row, int col)
{
	int **matrix = NULL;

	*matrix = (int *)declare_bitmap(row*col);

	return matrix;
}

int read_matrix(int **matrix, int row, int col)
{
	return get_bit(*matrix, row*col);
}

void write_matrix(int **matrix, int row, int col, int data)
{
	write_bit(*matrix, row*col, data);
}

void destroy_matrix(int **matrix)
{
	return destroy_bitmap(*matrix);
}
