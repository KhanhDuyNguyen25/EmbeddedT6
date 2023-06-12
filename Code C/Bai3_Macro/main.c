#include <stdio.h>

#define MAX 10

#define tong(a, b) a+b

#define CREATE_FUNC(name_func, cmd)     \
void name_func(){                       \
    printf("%s\n", (char*)cmd);         \
}

CREATE_FUNC(test, "Hello world");

CREATE_FUNC(test2, "How are you");

void Tong(int a, int b){        //  0xc1 - 0xc7
    printf("Tong cua a va b: %d", (a+b));
}

int main(int argc, char* argv[])   // programe counter 
{                                  // stack pointer
    printf("%d\n", MAX);
    printf("Tong %d\n", tong(10, 7));

    test();
    test2();

    // A  0x01 0x02 0x03
    // B  0x04  0x05 0x06
    // C  0x07 0x08
    Tong(7,9);
    
    return 0;
}