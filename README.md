# Embedded-Interview

<details>

<summary>
Struct & Union
</summary>

## **Struct** ##

Struct sắp xếp data theo biến có số byte lớn nhất

struct có kích thước là kích thước tổng member và bộ nhớ đệm (padding) và có địa chỉ là địa chỉ của member đầu tiên nên tùy vào cách sắp xếp các biến trong struct, ta sẽ có kích thước khác nhau nên ta phải sắp xếp sao cho tối ưu.

Khi nào dùng Struct: Struct cùng một thời điểm ta có thể chọn cùng lúc nhiều member
VD :

struct {

	uint8_t var1;   // 1 byte  
	uint32_t var2;  // 4byte   
	uint64_t var3;  // 8 byte  
}

Lần quét 1: lưu 1byte var1 và lưu được thêm 4byte var2 cùng 3byte bộ nhớ đệm. Lần quét 2: lưu hết 8 byte var3 => tổng hết 16 byte

struct {

	uint8_t var1;   // 1 byte  
	uint64_t var3;  // 8byte   
	uint32_t var2;  // 4 byte  
}

Lần quét 1: lưu 1byte var1 và 7byte bộ nhớ đệm. Lần quét 2: lưu hết 8 byte var3. Lần quét 3: lưu 4byte var2 và 4byte bộ nhớ đệm  => tổng hết 24 byte

## **Union** ##

union có kích thước là kích thước member lớn nhất (member chứ ko phải kiểu dữ liệu). 

Địa chỉ của union giống với địa chỉ các member dùng chung địa chỉ nên ta có thể thay đổi giá trị của union bằng cách thay đổi giá trị member

Khi nào dùng Union: Union có rất nhiều member và tại 1 thời điểm mình chỉ sử dụng 1 member trong đó thôi thì ta sẽ dùng Union (ví dụ: Khi đi ra HN, ta sẽ có nhiều cách di chuyển, nhưng ta chỉ có thể chọn 1 cách).

Vd

![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/78040569-2bfd-42ca-973c-f5a8c3331e76)

=> kích thước union = kích thước var2[10] =10*4=40byte, kích thước union = kích thước member (không phải kích thước kiểu dữ liệu)
có nghĩa là bằng kích thước của biến(var1,var2,var[3]) lớn nhất chứ không phải kiểu dữ liệu (uint8_t,float,uint64_t) lớn nhất

Vd 

![1](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/fb0f8e47-5d93-4ab3-b826-6dfe50b1d1a5)


=> xuất ra giá trị var1 là 0 3 4 6 4 5 vì xài chung địa chỉ với nhau nên khi thay đổi giá trị var2 và var3 var 1 cũng thay đổi theo thường được dùng trong việc giao tiếp giữa cái vđk mcu
union dùng khi phải đưa ra lựa chọn dùng 1 trong các member tại cùng 1 thời điểm còn struct thì dùng khi đc chọn nhiều member cùng lúc

</details>


<details>

<summary>
Macro & Funtion
</summary>

## **Macro** ##

Marco xảy ra trong quá trình tiền xử lý, lệnh #define được dùng để tạo marco

Vd: #DEFINE MAX 10

 #define CREATE_FUNC(name_func, cmd)   \
 void name_func(){                     \
      printf("%s\n", (char*)cmd);      \	    
 }
 
 Marco không có dấu chấm phẩy ở kết thúc vì không phải là câu lệnh
  
## **Function** ##

Hàm được khai báo với chức năng giải quyết một vấn đề nhiều lần. Hàm có thể có và không có tham số. Hàm có vùng nhớ riêng khi được tạo program counter có chức năng đếm giá trị vùng nhớ từ 0x00 -> hết ví dụ program counter đếm tới 0x08 thì gặp funtion thì trước khi vào function vùng nhớ tiếp theo 0x09 được lưu vào stack counter rồi program counter mới trỏ vào vùng nhớ của function để đếm xong thì nó lấy giá trị 0x09 trong stack counter ra tiếp tục đếm.

Program counter (bộ đếm): là 1 thanh ghi quản lý bộ nhớ của lệnh sẽ được thực thi tiếp theo. CPU đọc địa chỉ của lệnh sẽ được thực thi tiếp theo được lưu trữ trong bộ đếm chương trình và thực thi nó theo trình tự.

Stack pointer: lưu địa chỉ của item gần đây nhất được đặt trên ngăn xếp. (lưu địa chỉ ngẫu nhiên).

## **Ưu nhược điểm** ##

Ưu điểm của function là không tốn thêm kích thước nếu gọi hàm đó nhiều lần vì đã có vùng nhớ riêng cho function nhưng tốc độ lại chậm hơn vì mỗi lần gọi nó lại phải trỏ lại vùng nhớ lưu function đó nó ngược với define về ưu nhược điểm. Define nó chỉ thay biến bằng giá trị nên trong quá trình complier mỗi khi gặp biến đc define nó chỉ thay bằng giá trị vd MAX thì được thay bằng 10 nên program counter sẽ tiếp tục đếm tiếp khi gặp biến define làm cho tốn thêm kích thước lưu trữ

</details>



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

## **Static** ##

Static gồm static toàn cục (global) và static cục bộ (local). Được lưu ở phân vùng data hoặc bss và tồn tại hết vòng đời của chương trình.

*Static toàn cục (global) là biến, hàm được tạo ra và chỉ có giá trị trong file khởi tạo ra chúng. Vì là biến, hàm global nên ta có thể dùng chúng bất cứ khi nào cần nhưng không thể dùng chúng ở file khác vì là biến, hàm static.

*Static cục bộ (local) chỉ khởi tạo 1 lần duy nhất và giá trị sẽ không bị mất khi thoát khỏi hàm mà giá trị của biến có thể tích lũy.

## **Extern** ##

Extern dùng để gọi một biến hay một hàm từ file khác (không phải static) để sử dụng. Khi khai báo hàm hay biến dùng extern ta không được gán giá trị cho chúng. 

Câu lệnh: extern <kiểu dữ liệu> <tên biến hoặc hàm>;

Cách build chương trình: gcc main.c "tên file muốn build" -o main. Cách chạy chương trình: ./main

## **Volatile** ##

Biến volatile là biến thông báo cho complier biết không được tối ưu biến này (thường dùng cho các biến lấy giá trị cảm biến, các biến data không biết khi nào thay đổi, nhiều task chạy song song dùng chung 1 biến). Do compiler có chế độ tối ưu chương trình để tăng tốc độ của chương trình nên sẽ bỏ qua các câu lệnh không làm thay đổi giá trị hay các lệnh lặp được gọi là optimizing. Nhưng trong các trường hợp nêu trên, giá trị thay đổi nhưng compiler không nhận ra và thực hiện việc tối ưu khiến cho kết quá sai.

Câu lệnh: volatile <kiểu dữ liệu> <tên biến>;

</details>


<details>
<summary>
Language C++
</summary>

## **Class** ##
Class hay lớp là một mô tả trừu tượng (abstract) của nhóm các đối tượng (object) có
cùng bản chất, ngược lại mỗi một đối tượng là một thể hiện cụ thể (instance) cho
những mô tả trừu tượng đó. Một class trong C++ sẽ có các đặc điểm sau:
 Một class bao gồm các thành phần dữ liệu (thuộc tính hay property) và các
phương thức (hàm thành phần hay method).
 Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa.
 Trong C++, từ khóa class sẽ chỉ điểm bắt đầu của một class sẽ được cài đặt.
Ví dụ về một class đơn giản, class Car. Một chiếc xe hơi vậy thì sẽ có chung những
đặc điểm là đều có vô lăng, có bánh xe nhiều hơn 3, có động cơ… Đó là một class,
một cái model hay mẫu mà người ta đã quy định là nếu đúng như vậy thì nó là xe
hơi. Nhưng mà xe thì có thể có nhiều hãng khác nhau, BMW, Vinfast, Toyota… Thì
mỗi hãng xe lại có những model xe khác nhau nhưng chúng đều là xe hơi. Vậy thì
trong lập trình cũng vậy, class là quy định ra một mẫu, một cái model mà các thể
hiện của nó (instance) hay đối tượng (object) phải tuân theo.
## **Khai báo và sử dụng Class** ##
Ví dụ một class cơ bản:
class Person {
public:
string firstName; // property
string lastName; // property
int age; // property
void fullname() { // method
cout << firstName << ' ' << lastName;
}
};Cú pháp tạo object của một class và sử dụng các thuộc tính và phương thức:
Person person;
person.firstName = "Khiem";
person.lastName = "Le";
person.fullname(); // sẽ in ra màn hình là "Khiem Le"
## **Access modifiers & properties declaration** ##
Access modifier là phạm vi truy cập của các thuộc tính và phương thức sẽ được khai
báo bên dưới nó. Có 3 phạm vi truy cập trong C++ là public, private và protected.
 Các thuộc tính và phương thức khai báo public thì có thể được truy cập trực
tiếp thông qua instance của class đó. Các thuộc tính nên khai báo là public
nếu bạn không có ràng buộc điều kiện trước khi gán (người dùng có thể
thoải mái gán giá trị) hoặc bạn không cần xử lý trước khi trả về giá trị thuộc
tính;
 Các thuộc tính private thường được sử dụng khi bạn không mong muốn
người khác có thể tùy ý gán giá trị hoặc là bạn muốn xử lý trước khi trả về
giá trị.
 Đối với protected, các phương thức và thuộc tính chỉ có thể truy cập qua
các class kế thừa nó hoặc chính nó.

## **Ví dụ của access modifier:** ##
class MyClass
{
public:
int public_property;
private:
int _private_property;
};
## **Method declaration** ##
Phương thức cũng giống như một hàm bình thường.
Đối với phương thức thì có hai cách định nghĩa thi hành: định nghĩa thi hành trong
lúc định nghĩa class và định nghĩa thi hành bên ngoài class.
Định nghĩa thi hành bên trong class:
class Animal {
public:
string sound;
void makeNoise() {
cout << sound;
}
};
Định nghĩa thi hành bên ngoài class:
class Animal {
public:
string sound;
void makeNoise();
};
void Animal::makeNoise() {
cout << sound;
}
## **Constructor** ##
Constructor hay hàm dựng là một hàm đặc biệt, nó sẽ được gọi ngay khi chúng ta
khởi tạo một object.
class Person {
public:
string firstName;
string lastName;
int age;
Person(string _firstName, string _lastName, int _age)
{
firstName = _firstName;
lastName = _lastName;
age = _age;
}
void fullname() {
cout << firstName << ' ' << lastName;
}
};
## **Static member** ##
Static member hay thành viên tĩnh trong class C++ cũng tương tự như với static
variable (biến tĩnh) trong function. Đối với function, sau khi thực hiện xong khối
lệnh và thoát thì biến tĩnh vẫn sẽ không mất đi. Đối với class, thành viên tĩnh sẽ là
thuộc tính dùng chung cho tất cả các đối tượng của class đó, cho dù là không có đối
tượng nào tồn tại. Tức là bạn có thể khai báo nhiều object, mỗi object các thuộc tính
của nó đều khác nhau nhưng riêng static thì chỉ có một và static member tồn tại trong
suốt chương trình cho dù có hay không có object nào của nó hay nói ngắn gọn là
dùng chung một biến static.
## **Đặc tính của lập trình hướng đối tượng** ##
Có 4 đặc tính quan trọng của lập trình hướng đối tượng trong C++ mà chúng ta cần
nắm vững sau đây.
1. Inheritance (Tính kế thừa )
 trong lập trình hướng đối tượng có ý nghĩa, một class
có thể kế thừa các thuộc tính của một class khác đã tồn tại trước đó.
Khi một class con được tạo ra bởi việc kế thừa thuộc tính của class cha thì chúng ta
sẽ gọi class con đó là subclass trong C++, và class cha chính là superclass trong
C++.
2. Abstraction (Tính trừu tượng) 
 trong lập trình hướng đối tượng là một khả năng
mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông
tin cần xử lý.
Điều đó có nghĩa, bạn có thể xử lý một đối tượng bằng cách gọi tên một phương
thức và thu về kết quả xử lý, mà không cần biết làm cách nào đối tượng đó được các
thao tác trong class.
Ví dụ đơn giản, bạn có thể nấu cơm bằng nồi cơm điện bằng cách rất đơn giản là ấn
công tắc nấu, mà không cần biết là bên trong cái nồi cơm điện đó đã làm thế nào mà
gạo có thể nấu thành cơm.
3. Polymorphism (Tính đa hình) 
 trong lập trình hướng đối tượng là một khả năng mà
một phương thức trong class có thể đưa ra các kết quả hoàn toàn khác nhau, tùy
thuộc vào dữ liệu được xử lý.
Ví dụ đơn giản, cùng là một class quản lý dữ liệu là các con vật, thì hành động sủa
hay kêu của chúng được định nghĩa trong class sẽ cho ra kết quả khác nhau, ví dụ
nếu là con mèo thì kêu meo meo, còn con chó thì sủa gâu gâu chẳng hạn.
4. Encapsulation (Tính đóng gói) 
 trong lập trình hướng đối tượng có ý nghĩa không
cho phép người sử dụng các đối tượng thay đổi trạng thái nội tại của một đối tượng,
mà chỉ có phương thức nội tại của đối tượng có thể thay đổi chính nó.
Điều đó có nghĩa, dữ liệu và thông tin sẽ được đóng gói lại, giúp các tác động bên
ngoài một đối tượng không thể làm thay đổi đối tượng đó, nên sẽ đảm bảo tính toàn
vẹn của đối tượng, cũng như giúp dấu đi các dữ liệu thông tin cần được che giấu.
Ví dụ đơn giản, khi bạn dùng một cái iphone, bạn không thể thay đổi các cấu trúc
bên trong của hệ điều hành iOS, mà chỉ có Apple mới có thể làm được điều này thôi.
## **Namespace là gì?** ##
Tình huống:
Khi đang lập trình trong một file A bạn include 2 file B và C, nhưng 2 file này có
cùng định nghĩa một hàm function() giống nhau về tên và tham số truyền vào, nhưng
xử lý của mỗi hàm ở mỗi file là khác nhau, vấn đề đặt ra là code làm sao để trình
biên dịch hiểu được khi nào bạn muốn gọi function của file B, khi nào bạn muốn gọi
function của file C. Khi gọi hàm function() ở file A, trình biên dịch sẽ không biết
được hàm function() bạn muốn gọi là hàm được định nghĩa ở file B hay file C. Vì
vậy trình biên dịch chương trình sẽ báo lỗi.
Định nghĩa:
Namespace là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm
mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau.
## **Template trong C++ là gì?** ##
 Template (khuôn mẫu) là một từ khóa trong C++, và là một kiểu dữ liệu trừu
tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...
 Template trong C++ có 2 loại đó là function template & class template.
 Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì
phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu
dữ liệu khác nhau.
## **Hàm ảo (virtual function) là gì?** ##
Hàm ảo (virtual function) là một hàm thành viên trong lớp cơ sở mà lớp dẫn xuất
khi kế thừa cần phải định nghĩa lại.
Hàm ảo được sử dụng trong lớp cơ sở khi cần đảm bảo hàm ảo đó sẽ được định
nghĩa lại trong lớp dẫn xuất. Việc này rất cần thiết trong trường hợp con trỏ có
kiểu là lớp cơ sở trỏ đến đối tượng của lớp dẫn xuất.Hàm ảo là một phần không thể thiếu để thể hiện tính đa hình trong kế thừa được hỗ
trợ bởi nguồn ngữ C++.
Lưu ý: Con trỏ của lớp cơ sở có thể chứa địa chỉ của đối tượng thuộc lớp dẫn xuất,
nhưng ngược lại thì không được.
Hàm ảo chỉ khác hàm thành phần thông thường khi được gọi từ một con trỏ. Sử
dụng hàm ảo khi muốn con trỏ đang trỏ tới đối tượng của lớp nào thì hàm thành phần
của lớp đó sẽ được gọi mà không xem xét đến kiểu của con trỏ.
## **Vector là gì?** ##
Giống như là mảng (array), vector trong C++ là một đối tượng dùng để chứa các đối
tượng khác, và các đối tượng được chứa này cũng được lưu trữ một cách liên tiếp
trong vector.
Tuy nhiên, nếu như số lượng phần tử (size) của một mảng là cố định, thì ở vector,
nó hoàn toàn có thể thay đổi trong suốt quá trình làm việc của chương trình
Modifiers
1. push_back(): Hàm đẩy một phần tử vào vị trí sau cùng của vector. Nếu kiểu của
đối tượng được truyền dưới dạng tham số trong push_back() không giống với kiểu
của vector thì sẽ bị ném ra.
ten-vector.push_back(ten-cua-phan-tu);
2. assign(): Nó gán một giá trị mới cho các phần tử vector bằng cách thay thế các
giá trị cũ.
ten-vector.assign(int size, int value);
3. pop_back(): Hàm pop_back () được sử dụng để xóa đi phần tử cuối cùng một
vector.
4. insert(): Hàm này chèn các phần tử mới vào trước phần tử trước vị trí được trỏ
bởi vòng lặp. Chúng ta cũng có thể chuyển một số đối số thứ ba, đếm số lần phần tử
được chèn vào trước vị trí được trỏ.5. erase(): Hàm được sử dụng để xóa các phần tử tùy theo vị trí vùng chứa
6. emplace(): Nó mở rộng vùng chứa bằng cách chèn phần tử mới vào
7. emplace_back(): Nó được sử dụng để chèn một phần tử mới vào vùng chứa
vector, phần tử mới sẽ được thêm vào cuối vector
8. swap(): Hàm được sử dụng để hoán đổi nội dung của một vector này với một
vector khác cùng kiểu. Kích thước có thể khác nhau.
9. clear(): Hàm được sử dụng để loại bỏ tất cả các phần tử của vùng chứa vector.