#include"Header\SinhVien.hpp"

//constructor
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

int SinhVien::getID(){
            return ID;
        }

void SinhVien::setTen(string Ten){
            this -> TEN = Ten;
        }
string SinhVien::getTen(){
            return TEN;
        }

int SinhVien::getTuoi(){
            return TUOI;
        }
void SinhVien::setTuoi(int Tuoi){
            this -> TUOI = Tuoi;
        }

typeGioiTinh SinhVien::getGioi_Tinh(){
            return GIOI_TINH;
        }
void SinhVien::setGioi_Tinh(typeGioiTinh Gioi_Tinh){
           this-> GIOI_TINH = Gioi_Tinh;
        }

double SinhVien::getDiem_Toan(){
            return DIEM_TOAN;
        }
void SinhVien::setDiem_Toan(int Diem_Toan){
            this -> DIEM_TOAN = Diem_Toan;
        }

double SinhVien::getDiem_Ly(){
            return DIEM_LY;
        }
void SinhVien::setDiem_Ly(int Diem_Ly){
            this -> DIEM_LY = Diem_Ly;
        }

double SinhVien::getDiem_Hoa(){
            return DIEM_HOA;
        }
void SinhVien::setDiem_Hoa(int Diem_Hoa){
            this -> DIEM_HOA = Diem_Hoa;
        }

double SinhVien::getDiemTB(){
            return (DIEM_TOAN + DIEM_LY + DIEM_HOA)/3;
        }

string SinhVien::getHoc_Luc(){
            if(getDiemTB()>= 8){
                return "GIOI";
            }else if(getDiemTB() >=6.5 ){
                return "KHA";
            }else if(getDiemTB()>= 5){
                return "TRUNG BINH";
            }else{ 
                return "YEU";
                }
        }
