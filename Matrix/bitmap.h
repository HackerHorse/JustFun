#ifndef __BITMAP__
#define __BITMAP__

void *declare_bitmap(int size);
int get_bit(int *bitmap, int location);
int flip_bit(int *bitmap, int location);
void set_bit(int *bitmap, int location);
void write_bit(int *bitmap, int location, int bit);
void unset_bit(int *bitmap, int location);
void destroy_bitmap(int *bitmap);

#endif
