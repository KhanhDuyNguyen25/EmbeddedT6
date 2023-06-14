#include <stdio.h>

void tong(int a, int b){
    printf("Tong %d va %d =  %d\n", a, b, a+b);
}

void hieu(int a, int b){
    printf("Hieu %d va %d =  %d\n", a, b, a-b);
}

void tich(int a, int b){
    printf("Tich %d va %d =  %d\n", a, b, a*b);
}

double thuong(int a, int b){
    return (double)a/b;
}

void toanhoc(void (*ptr)(int a, int b), int a, int b){

    printf("Chuong trinh tinh toan\n");
    ptr(a, b);
}

int main(int argc, char *argv[]){

    void (*ptr)(int a, int b);

    ptr = &tong;
    ptr(71, 8);

    ptr = &hieu;
    ptr(71, 8);

    ptr = &tich;
    ptr(7, 8);

    double (*ptrD)(int, int) = &thuong;
    printf("Thuong: %f\n", ptrD(17, 4));

    toanhoc(&tich, 4 ,5);
    
    void *ptrT = &tong;
    ((void (*)(int, int))ptrT)(11, 2);
}