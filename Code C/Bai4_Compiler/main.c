#include <stdio.h>
#include "test.c"

#define MAX 10

void display()
{
    printf("Hello world!\n");
}

int main(int argc, char *argv[])
{

    display();
    printf("Max: %d\n", MAX);

    test();
    return 0;
}