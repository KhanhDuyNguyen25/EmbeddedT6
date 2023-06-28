#include <stdio.h>
#include <stdbool.h>

bool  isEqual(const char arr1[], const char arr2[]){
int i =0;
while(arr1 [i] == arr2[i])
{
    if(arr1[i] == '\0') return true;
    i++;
}


}

typedef enum{
    SMALLER,
    BIGGER,
    EQUAL
}Compare;

bool SoSanh2(const char arr1[], const char arr2[]){


struct 
{
    int length;
    char *array;
};

}

int main(int argc, char const *argv[]){

    char arr1[] = "hello";

    char arr2[] = "this is test";

    printf("sosaanh: %d\n", isEqual(arr1, arr2));


}