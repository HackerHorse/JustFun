#ifndef __BITMAP__
#define __BITMAP__

int *declare_bitmap(int size);
int get_bit(int location);
int flip_bit(int location);
int set_bit(int location);
int destroy_bitmap(int *bitmap);

#endif __BITMAP__
