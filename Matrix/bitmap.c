#include <stdio.h>
#include <malloc.h>

#include "bitmap.h"
#include "logger.h"

#define GET_INDEX(location) (location / BLOCK_SIZE)
#define GET_OFFSET(location)(location % BLOCK_SIZE)

#define SET_BIT(bitmask)	(1 << bitmask)
#define UNSET_BIT(bitmask)	(~(1 << bitmask))

void* declare_bitmap(int size)
{
	LOG_MSG(ERR, "Sizeof allocatopn:%d", size);
	return calloc(size, sizeof(int));
}

void destroy_bitmap(int *bitmap)
{
	if (bitmap)
		free(bitmap);
}

int get_bit(int *bitmap, int location)
{
	int index = GET_INDEX(location);
	int offset = GET_OFFSET(location);
	return ((bitmap[index] & SET_BIT(offset)) ? 1 : 0);
}

int flip_bit(int *bitmap, int location)
{
	return 0;
}

void set_bit(int *bitmap, int location)
{
	int index = GET_INDEX(location);
	int offset = GET_OFFSET(location);

	bitmap[index] |= SET_BIT(offset);
}

void unset_bit(int *bitmap, int location)
{
	int index = GET_INDEX(location);
	int offset = GET_OFFSET(location);

	bitmap[index] &= UNSET_BIT(offset);
}
