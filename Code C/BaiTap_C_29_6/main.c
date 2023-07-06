#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>



uint16_t random_number(uint16_t minN, uint16_t maxN){
 return minN + rand() % (maxN + 1 - minN);
}

uint16_t *createArray(uint16_t length){
    uint16_t *ptr = (uint16_t*)malloc(sizeof(uint16_t)*length);
    srand((int)time(0));
    for (uint16_t i = 0; i < length; i++)
    {
        ptr[i] = random_number(1, 10);
    }
    return ptr; 
}

void sort(uint16_t array[], uint16_t length){

    for(int i = 0; i < length; i++){
        for(int j = i+1; j < length; j++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int SearchID(uint16_t array[], uint16_t length, uint16_t ID){

    uint16_t end = length-1;  // chỉ số phần tử cuối
    uint16_t start = 0;      // Chỉ số phần tử đầu tiên
    while(end > start){
        uint16_t mid = start + (end-1)/2;

        // Nếu array[mid] = x, trả về chỉ số và kết thúc.
        if(array[mid] == ID){
            return mid;
        }

         // Nếu array[mid] > ID, cập nhật lại end
        if(array[mid] > ID){
            end = mid - 1;
        }

        // Nếu array[mid] < ID, cập nhật lại start
        if(array[mid] < ID){
            start = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
   uint16_t *array = createArray(10);
   uint16_t ID = 5;

   sort(array, 10);
   for(int i = 0; i<10; i++){
    printf("arr[%d] = %d\n", i, array[i]);
   }
   uint8_t result = SearchID(array, 10, ID);
   if(result = -1){
    printf("Khong phat hien ID");
   }else{
    printf("Vi tri cua ID: %d", result);
   }
    return 0;
}
