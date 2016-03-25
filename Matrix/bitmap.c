#include <stdio.h>
#include <malloc.h>

#include "bitmap.h"

#define BLOCK_SIZE (sizeof(int)*sizeof(char))

#define GET_INDEX(location) (location / BLOCK_SIZE)
#define GET_BITMASK(location) (location % BLOCK_SIZE)

#define SET_BIT(bitmask)	(1 << bitmask)
#define UNSET_BIT(bitmask)	(~(1 << bitmask))

void* declare_bitmap(int size)
{
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
	int bit_mask = GET_BITMASK(location);
	return bitmap[index] & bit_mask;
}

void write_bit(int *bitmap, int location, int bit)
{
	if(bit)
		unset_bit(bitmap, location);
	else
		set_bit(bitmap, location);
}

int flip_bit(int *bitmap, int location)
{
	return 0;
}

void set_bit(int *bitmap, int location)
{
	int index = GET_INDEX(location);
	int bit_mask = GET_BITMASK(location);

	bitmap[index] |= SET_BIT(bit_mask);
}

void unset_bit(int *bitmap, int location)
{
	int index = GET_INDEX(location);
	int bit_mask = GET_BITMASK(location);

	bitmap[index] &= UNSET_BIT(bit_mask);
}
