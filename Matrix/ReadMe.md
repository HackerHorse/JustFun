Compile.

1. Run "make" in the source directory. It will create libmatrix.so

Make your application to include "matrix.h" and link it with libmatrix.so

Example:
In the Test directory, I have provided a sample application.

>gcc main.c -o exec -I <path-to-matrix.h> -L <path-to-libmatrix.so> -lmatrix

Make sure you have LD_LIBRARY_PATH set to point to libmatrix.so.

>export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<path-to-libmatrix.so>
