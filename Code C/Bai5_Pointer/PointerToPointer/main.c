#include <stdio.h>
 
int main()
{

    int a = 10;
    int *ptr = &a;
    int **ptp =&ptr;

    printf("Dia chi cua con tro ptr: %p, gia tri = %d\n", ptp, **ptp);


    int var = 123;
 
    int* ptr2;
 
    int** ptr1;
 
    ptr2 = &var;
 
    ptr1 = &ptr2;
 
    printf("Gia tri var = %d\n", var);
    printf("Gia tri *pointer = %d\n", *ptr2);
    printf("Gia tri **pointer = %d\n", **ptr1);




 
    return 0;
}