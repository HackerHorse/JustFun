#ifndef __BITMAP__
#define __BITMAP__

#define BYTE_SIZE 8 /* As if it is going to change */

#define BLOCK_SIZE (sizeof(int)*BYTE_SIZE)

void *declare_bitmap(int size);
int get_bit(int *bitmap, int location);
int flip_bit(int *bitmap, int location);
void set_bit(int *bitmap, int location);
void unset_bit(int *bitmap, int location);
void destroy_bitmap(int *bitmap);

#endif
