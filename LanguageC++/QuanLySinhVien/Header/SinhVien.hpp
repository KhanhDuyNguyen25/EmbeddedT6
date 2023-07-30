
#ifndef SINHVIEN_HPP
#define SINHVIEN_HPP

#include <string>
using namespace std;

typedef enum{
    NAM,
    NU 
}typeGioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}typeHocLuc;

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

       int getID();
       string getTen();
       int getTuoi();
       string getGioi_Tinh();
       double getDiem_Toan();
       double getDiem_Ly();
       double getDiem_Hoa();
       double getDiemTB();
       string getHoc_Luc();

       void setTen(string Ten);
       void setTuoi(int Tuoi);
       void setGioi_Tinh(typeGioiTinh Gioi_Tinh);
       void setDiem_Toan(int Diem_Toan);
       void setDiem_Ly(int Diem_Ly);
       void setDiem_Hoa(int Diem_Hoa);

};

#endif // SINHVIEN_HPP