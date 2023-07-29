#include <iostream>
#include<list>
#include<string>

using namespace std;

/*
 * Function: MACRO ENTER_INFORMATION
 * Description: Macro phần nhập thông tin Sinh Viên
 * Input:
 *   content - Nội dung cần nhập
 *   format - định dạng kiểu dữ liệu
 *   variable - biến cần nhập vào
 *   condition - điều kiện để nhập
 */
#define ENTER_INFORMATION(content, format, variable, condition) \
    do                                                          \
    {                                                           \
        cout << content;                                        \
        cin >> format >> variable;                              \
    } while (condition)

/*
 * Function: MACRO PRINT_INFORMATION
 * Description: Macro phần hiển thị thông tin Sinh Viên
 * Input:
 *   object - đối tượng cần hiển thị
 */
#define PRINT_INFORMATION(object)                                                          \
    cout << object.getID()<<"\t"<< object.getTen() <<"\t" << object.getTuoi() <<"\t"       \
           << object.getGioi_Tinh() <<"\t";                                                \
    cout<< object.getDiem_Toan() <<"\t"<< object.getDiem_Ly() <<"\t"<<                     \
           object.getDiem_Hoa();                                                           \
   cout << object.getDiem_Trung_Binh() << "\t"<< object.getHoc_Luc()


 /* Function: MACRO DOWHILE_METHODMENU
 * Description: Macro sử dụng chức năng của từng method
 * Input:
 *   content - Nội dung chức năng của từng method
 */
#define DOWHILE_METHODMENU(content)                            \
    do                                                         \
    {                                                          \
        content                                                \
        cout << "- Nhan phim '0' => De Thoat chuc nang\n";     \
        cin >> key;                                            \
    } while (key == 1)

typedef enum{
    NAM,
    NU
}typeGioiTinh;

/*typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}typeHocLuc;*/

class SinhVien{

    private:
        int ID;
        string TEN;
        int TUOI;
        typeGioiTinh GIOI_TINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;
        double DIEM_TRUNG_BINH;
        string HOC_LUC;
    public:
        SinhVien(string Ten, int Tuoi, typeGioiTinh Gioi_Tinh,
         double Diem_Toan, double Diem_Ly, double Diem_Hoa);

        int getID(){
            return ID;
        }

        void getTen(string Ten){
            this -> TEN = Ten;
        }
        string getTen(){
            return TEN;
        }

        int getTuoi(){
            return TUOI;
        }
        void setTuoi(int Tuoi){
            this -> TUOI = Tuoi;
        }

        typeGioiTinh getGioi_Tinh(){
            return GIOI_TINH;
        }
        void getGioi_Tinh(typeGioiTinh Gioi_Tinh){
            this -> GIOI_TINH = Gioi_Tinh;
        }

        double getDiem_Toan(){
            return DIEM_TOAN;
        }
        void setDiem_Toan(int Diem_Toan){
            this -> DIEM_TOAN = Diem_Toan;
        }

        double getDiem_Ly(){
            return DIEM_LY;
        }
        void setDiem_Ly(int Diem_Ly){
            this -> DIEM_LY = Diem_Ly;
        }

        double getDiem_Hoa(){
            return DIEM_HOA;
        }
        void setDiem_Hoa(int Diem_Hoa){
            this -> DIEM_HOA = Diem_Hoa;
        }

        double getDiem_Trung_Binh(){
            return (DIEM_TOAN + DIEM_LY + DIEM_HOA)/3;
        }
        string getHoc_Luc(){
            double DiemTB = getDiem_Trung_Binh();
            if(DiemTB >= 8){
                return "Gioi";
            }else if(DiemTB >=6.5 ){
                return "Kha";
            }else if(DiemTB >= 5){
                return "Trung binh";
            }else{ 
                return "Yeu";
                }
        }
};

SinhVien::SinhVien(string Ten, int Tuoi, typeGioiTinh Gioi_Tinh, 
        double Diem_Toan, double Diem_Ly, double Diem_Hoa){

         static int id = 1000;
            ID = id;
            id++;
        TEN = Ten;
        TUOI = Tuoi;
        GIOI_TINH = Gioi_Tinh;
        DIEM_TOAN = Diem_Toan;
        DIEM_LY = Diem_Ly;
        DIEM_HOA = Diem_Hoa;
        }

void ThemSinhVien(list<SinhVien> &database){
    string Ten;
    int Tuoi;
    typeGioiTinh Gioi_Tinh;
    double Toan;
    double Ly;
    double Hoa;
    bool key;
    
    DOWHILE_METHODMENU
    (
        cout <<"/* KHAI BAO THONG TIN SINH VIEN */" << endl;
        ENTER_INFORMATION("Nhap ten: ", Ten, 0);

        ENTER_INFORMATION("Nhap tuoi: ", Tuoi, Tuoi>100||Tuoi<1);
        
        ENTER_INFORMATION("Nhap gioi tinh: ", Gioi_Tinh, 0);

        ENTER_INFORMATION("Nhap diem toan: ",Toan, Toan > 10||Toan < 0);

        ENTER_INFORMATION("Nhap diem ly: ", Ly, Ly > 10||Ly < 0);

        ENTER_INFORMATION("Nhap diem hoa: ",Hoa, Hoa > 10||Hoa < 0);

        SinhVien::SinhVien(Ten, Tuoi, Gioi_Tinh, Toan, Ly, Hoa);

        SinhVien.push_back(database);

        cout << "Nhan phim '1' => De tiep tuc them sinh vien\n"<<endl;

    );
}

int main(){

    list<SinhVien> database;

    return 0;
}