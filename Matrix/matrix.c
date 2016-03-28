#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"
#include "bitmap.h"

typedef struct header {
	int row;
	int col;
} dimension_t;

#define EXTRACT_DIM(a,b) (a = (dimension_t *)(b[1]));

#define GET_ELEM_LOCATION(dim, r, c) ((r*dim->col)+c)

int **decl_matrix(int row, int col)
{
	int **matrix;
	dimension_t *dim;

	matrix = (int **)malloc(sizeof(void *)*2);
	if (matrix == NULL)
		goto out;

	matrix[0] = NULL;
	matrix[0] = (int *)declare_bitmap((row*col)/(BLOCK_SIZE)+ 1);
	if (matrix[0] == NULL) {
		free(matrix);
		matrix = NULL;
		goto out;
	}
	/* Insert header: This dirty work has to be done to 
         * to efficiently calculate the bit number in the function 
         */
	dim = (dimension_t *)malloc(sizeof(dimension_t));
	if (dim == NULL) {
		free(*matrix);
		free(matrix);
		matrix = NULL;
		goto out;
	}

	dim->row = row;
	dim->col = col;
	matrix[1] = (void *)dim;
out:
	return matrix;
}

int read_matrix(int **matrix, int row, int col)
{
	dimension_t *dim;

	EXTRACT_DIM(dim, matrix);

	return get_bit(*matrix, GET_ELEM_LOCATION(dim, row, col));
}

void write_matrix(int **matrix, int row, int col, int data)
{
	dimension_t *dim;
	EXTRACT_DIM(dim, matrix);

	if (data)
		set_bit(*matrix, GET_ELEM_LOCATION(dim, row, col));
	else
		unset_bit(*matrix, GET_ELEM_LOCATION(dim, row, col));
}

void destroy_matrix(int **matrix)
{
	destroy_bitmap(*matrix);
	free(matrix[1]);
	free(matrix);
}
