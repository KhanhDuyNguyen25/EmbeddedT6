# Embedded-Interview
<details>

<summary>
Compiler
</summary>
 
### Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi.
Ngôn ngữ lập trình C++ là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C++ muốn chạy được trên máy tính phải trải qua
một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:

### ![alt](https://github.com/KhanhDuyNguyen25/EmbeddedT6/assets/124339492/dd5ffb06-9f95-4995-bddc-c2e4795c8932)

## **HOẠT ĐỘNG**

###  Giai đoạn tiền xử lý – Preprocessor Bộ tiền xử lý có nhiệm vụ thực hiện:
#### + Nhận mã nguồn
#### + Xóa bỏ tất cả chú thích, comments của chương trình
#### + Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý Chúng ta có thể bắt lỗi ngay ở giai đoạn này với việc sử dụng một cách hợp lý 
các chỉ thị #if và #error. Bằng cách sử dụng option -E của trình biên dịch như bên dưới, chúng ta có thể dừng quá trình biên dịch ngay ở 
giai đoạn tiền xử lý nếu có lỗi ở giai đoạn này.
####   Ví dụ: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được 
định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.
 
![1](https://github.com/KhanhDuyNguyen25/EmbeddedT6/assets/124339492/013c08c7-beaf-4779-900d-5332364dea6b)

 ####Sau khi thực hiện tiền xử lý
 
![2](https://github.com/KhanhDuyNguyen25/EmbeddedT6/assets/124339492/6c64d548-1b7d-4263-954c-c198d2a48782)

 
###   Compilation (biên dịch)
####  + Phân tích cú pháp (syntax) của mã nguồn NNBC.
####  + Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.

![3](https://github.com/KhanhDuyNguyen25/EmbeddedT6/assets/124339492/ed125aca-6b51-48eb-8a61-c6b7604ba117)


###   Công đoạn dịch Assembly
####  + Dich chương trình => Sang mã máy 0 và 1
####  + Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.


###   Giai đoạn Linker
####  + Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau
để tạo thành chương trình đích duy nhất Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính
không có hàm main() cũng được phát hiện trong liên kết.
</details>

<details>
<summary>
 Pointer
</summary>

## Void Pointer
 - `Con trỏ void có thể trỏ đến các vùng nhớ có các kiểu dữ liệu khác nhau`.
 - Tuy nhiên, con trỏ void không xác định được kiểu dữ liệu của vùng nhớ mà nó trỏ tới, vì vậy không thể truy cập xuất trực tiếp nội dung thông qua toán tử derefernce () được. Mà `con trỏ kiểu void` cần `phải được ép kiểu` một cách rõ ràng `sang con trỏ có kiểu dữ liệu khác trước khi sử dụng toán tử derefernce` ().
 ```
 #include <stdio.h>

void tong(int a,int b){
    printf("tong %d va %d = %d\n", a, b, a + b);
}

int main()
{

    int i = 3;
    double d =12.4;
    char c ='B';

    // con trỏ void có thể trỏ đến bất kỳ địa chỉ nào 
    void *ptr = &i;

    // để lấy giá trị từ con trỏ void ta cần ép kiểu nó
    printf("i = %d\n",*(int *)ptr);

    ptr = &d;
    printf("d = %f\n",*(double *)ptr);

    ptr = &c;
    printf("c = %c\n",*(char *)ptr);

    ptr = &tong;
    ((void (*)(int, int))ptr)(9,1);
    return 0;
}
   
  ```
 
## Null Pointer
- Con trỏ null là con trỏ có giá trị và địa chỉ bằng 0.
- Khi khai báo 1 con trỏ:
    + Phải khai báo địa chỉ cho nó.
    + Nếu mà chưa sử dụng thì gán cho nó con trỏ null. 
    + Hoặc khi khai báo con trỏ và đã sử dụng nó rồi, khi không muốn sử dụng nó nữa thì phải gán nó lại là con trỏ null.
```
    int *ptr = NULL;
```
## Function Pointer
- Sau khi khai báo thì hàm cũng được lưu trữ tại một địa chỉ trong bộ nhớ, và do đó, chúng ta cũng có thể sử dụng con trỏ để lưu trữ địa chỉ và qua đó thao tác với chúng.
- Chúng ta gọi con trỏ lưu trữ địa chỉ của một hàm là con trỏ hàm trong c, và sử dụng nó để truy cập vào địa chỉ của hàm, cũng như thực thi các xử lý bên trong hàm đó.
 ```
    Cách khai báo:
        type (*fp) ( para_type_1, para_type_2, para_type_3,...);
    fp: tên con trỏ hàm.
    type: kiểu của con trỏ.
    para_type_1,.. : các kiểu của các đối số parameter.
 ```
 ```
 VD:
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
    
 
 ```
 ## Pointer to Pointer
 Con trỏ trỏ đến con trỏ (Pointers to pointers) là một con trỏ chứa địa chỉ của một con trỏ khác.
    
 ```
  cách khai báo: 
   data_type_of_pointer **name_of_variable = & normal_pointer_variable;
 ```
 
 ```
int val = 5; 
int *ptr = &val; // lưu địa chỉ của val vào con trỏ ptr. 
int **d_ptr = &ptr; // con trỏ tới một con trỏ được khai báo 
                    // đang trỏ tới một số nguyên.
    
 ```
 ```
 VD :
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
 ```
</details>

<details>
<summary>
Memory partition
</summary>

![memory](https://github.com/KhanhDuyNguyen25/EmbeddedT6/assets/124339492/0ce0dc04-23aa-423b-a5c3-bb5c41041325)


**TEXT:** 
+ Có quyền truy cập read và chứa lệnh thực thi nên tránh sửa đổi ( Ví dụ như nạp một file.hex cho vi điều khiển, thì file.hex nằm ở bộ nhớ flash, khi chạy sẽ copy chương trình này tại bộ nhớ ram tại phân vùng text).
+ Chứa khai báo hằng số trong chương trình VD : `const int a = 10;`
+ Lưu ý: Data nào nằm ở phân vùng text chỉ đọc chứ không sửa được.

**DATA:** 
+ Quyền truy cập read và write.
+ Chứa biến toàn cục hoặc biến static với giá trị khởi tạo khác không.
+ Được giải phóng khi kết thúc chương trình

Ví dụ : 
```sh
#include <stdio.h>

int i =10;// bien toan cuc nam o phan vung data
static int i =5;// bien static toan cuc nam o phan vung data
void tong()
{
int x;// bien cuc bo
static int c =5;// bien static cuc bo nam o phan vung data
}
```

**BSS:** 
+ Quyền truy cập read và write.
+ Chứa biến toàn cục hoặc biến static với giá trị khởi tạo bằng 0 hoặc không khởi tạo.
+ Được giải phóng khi kết thúc chương trình.

Ví dụ:
```sh
#include <stdio.h>

int i ;// bien toan cuc nam o phan vung bss (khong khoi tao gia tri)
static int i =0;// bien static toan cuc nam o phan vung bss ( bang 0)
void tong()
{
static int c;// bien static cuc bo nam o phan vung bss (khong khoi tao gia tri)
}
```

**STACK:** 
+ Quyền truy cập là read và write.
+ Được sử dụng cấp phát cho biến local, input parameter của hàm.
+ Sẽ được giải phóng khi thoát ra khỏi block code hàm.
  Ví dụ:
  
```sh
#include <stdio.h>

int tong(int a, int b);{ // a ,b duoc luu o phan vung stack
int c; // bien cuc bo luu o phan vung stack
c = a+b; // bien cuc bo luu o phan vung stack
return c;
}

int main(int argc, char const* argv[]){
int x = tong(5 ,7);// int a = 5 // 0x01
                    // int b = 7 // 0x02
                    // int c //0x03
                    //c =a+b
                    // return c; // khi thoat ra dia chi a,b,c bi thu hoi
tong (7, 10);// khi goi ra cung chay ra tuong tu nhung co the nam o dia chi khac do dia chi cu 
                da bi thu hoi
return 0;
}
```

Ứng dụng của con trỏ , Ví dụ :
```sh
#include <stdio.h>
  
void swap(int a, int b);{
int temp = a; //int a =10 // 0x01
a =b;          // int b = 20 //0x02
b = temp;
}

int main(int argc, char const* argv[]){
int x = 10; // 0xc1
int y = 20;//0xc2
swap (x,y);
printf("x =%d, y=%d,x,y);
return 0;
```
*Khi chạy hàm swap giá trị của a và b được gán cho x và y và được đổi giá trị cho nhau, nhưng sau khi kết thúc hàm thì giải phóng địa chỉ => reset lại nên chương trình vẫn trả về kq x= 10, y= 20*

```sh
#include <stdio.h>
  
void swap(int *a, int *b);{
int temp = *a; //int *a = 0xc1 // gán giá trị temp = giá trị của a là 10
*a =*b;          // int b = 0x02 // gán giá trị của a =b = 20
*b = temp; // gán giá trị của b = 10
}

int main(int argc, char const* argv[]){
int x = 10; // 0xc1
int y = 20;//0xc2
swap (&x,&y);
printf("x =%d, y=%d,x,y);
return 0;
```
*Khi chạy hàm swap địa chỉ của a và b được gán cho x và y và được đổi giá trị cho nhau,  sau khi kết thúc hàm thì do cùng địa chỉ nên giá trị của x và y được đổi cho nhau => trả về kq x= 20, y= 10*

**CHÂN LÝ:** Sử dụng biến khi muốn đọc giá trị của input và parameter, sử dụng biến con trỏ khi muốn thay đổi giá trị của input và parameter.

**HEAP:** 
+ Quyền truy cập read và write.
+ Được sử dụng để cấp phát bộ nhớ động như : Malloc(kieu con tro void), Calloc,...
+ Sẽ giải phóng khi gọi hàm free. VD `free(tenbien);`

**Lưu ý:** Địa chỉ của mảng giống địa chỉ của member đầu tiên, địa chỉ của mảng liền kề nhau, cách nhau mỗi đơn vị của mảng đó
Ví dụ `int array[] = {1,3,5,7};// dia chi array = array[1], moi dia chi cach nhau 4 byte`

Ví dụ
```sh
#include <stdio.h>
#include <stdint.h>
#inlcude <stdlib.h>

int main(int argc, char const* argv[]){
int *array = (int*)malloc(sizeof(int)*4); //gan ham malloc gia tri int, 4 ky tu // luu o heap
for (int i =0; i <4; i++)
{
array [i]=3*i; // gan gia tri cho ham array[4] = { 0,3,6,9);
}
array = (int*)realloc(array, sizeof(int)*7);// cap phat them gia tri, 7 ky tu // luu o heap
for (int i =0; i <7; i++)
{
array [i]=2*i; // gan gia tri cho ham array[7] = { 0,2,4,6,8,10,12);
}
return 0; }
```
</details>


<details>
<summary>
Static-Extern-Voltalite
</summary>

**STATIC**

Static gồm static toàn cục (global) và static cục bộ (local). Được lưu ở phân vùng data hoặc bss và tồn tại hết vòng đời của chương trình.

*Static toàn cục (global) là biến, hàm được tạo ra và chỉ có giá trị trong file khởi tạo ra chúng. Vì là biến, hàm global nên ta có thể dùng chúng bất cứ khi nào cần nhưng không thể dùng chúng ở file khác vì là biến, hàm static.

*Static cục bộ (local) chỉ khởi tạo 1 lần duy nhất và giá trị sẽ không bị mất khi thoát khỏi hàm mà giá trị của biến có thể tích lũy.

**EXTERN**

Extern dùng để gọi một biến hay một hàm từ file khác (không phải static) để sử dụng. Khi khai báo hàm hay biến dùng extern ta không được gán giá trị cho chúng. 

Câu lệnh: extern <kiểu dữ liệu> <tên biến hoặc hàm>;

Cách build chương trình: gcc main.c "tên file muốn build" -o main. Cách chạy chương trình: ./main

**VOLATILE**

Biến volatile là biến thông báo cho complier biết không được tối ưu biến này (thường dùng cho các biến lấy giá trị cảm biến, các biến data không biết khi nào thay đổi, nhiều task chạy song song dùng chung 1 biến). Do compiler có chế độ tối ưu chương trình để tăng tốc độ của chương trình nên sẽ bỏ qua các câu lệnh không làm thay đổi giá trị hay các lệnh lặp được gọi là optimizing. Nhưng trong các trường hợp nêu trên, giá trị thay đổi nhưng compiler không nhận ra và thực hiện việc tối ưu khiến cho kết quá sai.

Câu lệnh: volatile <kiểu dữ liệu> <tên biến>;

</details>
