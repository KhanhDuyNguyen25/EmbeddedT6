#include <stdio.h>

int Lengh(char *arr){
    int i = 0;
    while(arr[i] != '\0')
    {
        i++;
    }
   return i;

}

void ReveresString(char *arr, int start, int end){
    while(start < end){
        char temp  = arr[start];
        arr[start] = arr[end];
        arr[end]   = temp;
        start++;
        end--;
    }
}

void ReveresWord(char *arr)
{
    int lengh = Lengh(arr);
    int start =0;

    for(int i = 0; i <= lengh; i++){
        if(arr[i]==' '||arr[i]=='\0'){
            ReveresString(arr, start, i-1);
            start = i + 1;
        }
    }
    ReveresString(arr, 0, lengh-1);
}
