#include <stdio.h>
#include "library/header.h"
int main(int argc, char const *argv[])
{  
    int i = 0;
    char arr[] = "Nguyen Khanh Duy";

    printf("Kich thuoc chuoi: %d\n", Lengh(arr) );

    printf("INPUT: %s\n", arr);

    ReveresWord(arr);

    printf("OUTPUT: %s", arr);
    return 0;
}