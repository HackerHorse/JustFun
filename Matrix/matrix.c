#include "matrix.h"

int **decl_matrix(int row, int col)
{
	int **matrix = NULL;

	matrix = decl_bitmap(row, col);

	return matrix;
}
