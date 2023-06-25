#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include<string.h>

int main(int argc, char *argv[]){

    char array[] = "365.25 7.0";

    char *pend;

    float f1 = strtof(array, &pend);

    printf("f1: %f\n", f1);

    float f2 = strtof(pend, NULL);

    printf("f2: %f\n", f2);
}