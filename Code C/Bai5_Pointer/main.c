#include <stdio.h>
#include <string.h>

int tong(int a, int b){
    return (int*)a+b;
}

int a = 10;

void toanhoc(){

}

int main(int argc, char * argv[]){

  printf("Dia chi: %p\n", &tong);
  
  int *ptr = &a;
  printf("Gia tri a = %d\n", *ptr);

  // CON TRO VOID

  char c = 'A';
  double d = 12.2;

  void *ptrV;

  ptrV = &a;
  printf("Dia chi cua a: %p, gia tri = %d\n", ptrV, *(int*)ptrV);

  ptrV = &c;
  printf("Dia chi cua c: %p, gia tri = %c\n", ptrV, *(char*)ptrV);

  ptrV = &d;
  printf("Dia chi cua d: %p, gia tri = %f\n", ptrV, *(double*)ptrV);

     
  char string[]= "Hello";

  // CON TRO NULL (  int *ptr = NULL; co dia chi mac dinh la 0, khi khai baso con  tro ma chua dung toi thi dung NULL pointer)

 // CON TRO HAM

  void (*ptrF)(int, int);

  *(int*)ptrF = &tong;

  ptrF(71, 8);


  //  void *array[] ={&toanhoc, &d, string};
  
}