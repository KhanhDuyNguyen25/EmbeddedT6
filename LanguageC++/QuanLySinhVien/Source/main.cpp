#include <iostream>
#include <stdio.h>
#include <list>
#include "../Header/SinhVien.hpp"
#include <cassert>

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

void SinhVien::setGioi_Tinh(typeGioiTinh Gioi_Tinh){
           this-> GIOI_TINH = (typeGioiTinh)Gioi_Tinh;
        }

string SinhVien::getGioi_Tinh(){
    switch (GIOI_TINH)
    {
    case NAM:
        return "Nam";
        break;
    case NU:
        return "Nu";
        break;
    default:
        return "Khong hop le";
        break;
    }
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

void ThemSinhVien(list<SinhVien> & database){

    string TEN;
    int TUOI;
    typeGioiTinh GIOI_TINH;
    double DIEM_TOAN;
    double DIEM_LY;
    double DIEM_HOA;

    cout << "Nhap ten sinh vien: ";
    cin >>TEN;

    cout << "Nhap gioi tinh (NAM: 0/NU: 1): ";
    int inGioiTinh;
    cin >> inGioiTinh;
    GIOI_TINH = (typeGioiTinh)inGioiTinh;

    cout << "Nhap tuoi sinh vien: ";
    cin >> TUOI;

    cout << "Nhap diem Toan: ";
    cin >> DIEM_TOAN;

    cout << "Nhap diem Ly: ";
    cin >> DIEM_LY;

    cout << "Nhap diem Hoa: ";
    cin >> DIEM_HOA;
    
    assert(!TEN.empty() && "Ten khong duoc de trong");
    assert( 17< TUOI <100 && "Tuoi phai lon hon 17");
    assert(0 <= DIEM_TOAN <= 10 && "Diem toan phai giua 0 va 10");
    assert(0 <= DIEM_LY <= 10 && "Diem ly phai giua 0 va 10");
    assert(0 <= DIEM_HOA <= 10 && "Diem hoa phai giua 0 va 10");

    SinhVien ThemSV(TEN, TUOI, GIOI_TINH, DIEM_TOAN, DIEM_LY, DIEM_HOA);

    database.push_back(ThemSV);

    cout <<"Them sinh vien thanh cong "<<endl;

}

void updateSinhVien(list<SinhVien> &database) {
   int ID;
   cout <<"Nhap ID sinh vien: "<<endl;
   cin>>ID;

   bool ref = 0;
   for(auto &sv : database){
    if(sv.getID() == ID){
        string TEN;
        int TUOI;
        typeGioiTinh GIOI_TINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;
        cout<<"Ten:"<<sv.getTen()<<endl;
        cout<<"Tuoi:"<<sv.getTuoi()<<endl;
        cout<<"Gioi Tinh:"<<sv.getGioi_Tinh()<<endl;
        cout<<"Diem Toan:"<<sv.getDiem_Toan()<<endl;
        cout<<"Diem Ly:"<<sv.getDiem_Ly()<<endl;
        cout<<"Diem Hoa:"<<sv.getDiem_Hoa()<<endl;
        int choose;
        do {
        cout << "\n------- Menu -------" << endl;
        cout << "1. Cap nhat ten moi" << endl;
        cout << "2. cap nhat tuoi moi" << endl;
        cout << "3. Cap nhat gioi tinh moi" << endl;
        cout << "4. Cap nhat diem toan" << endl;
        cout << "5. Cap nhat diem ly" << endl;
        cout << "6. Cap nhat diem hoa" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choose;

        switch (choose) {
            case 1:
                cout<<"Nhap ten moi:"<<endl;
                cin>> TEN;
                sv.setTen(TEN);
                break;
            case 2:
                cout<<"Nhap tuoi moi:"<<endl;
                cin>> TUOI;
                sv.setTuoi(TUOI);
                break;
            case 3:
                cout<<"Nhap gioi tinh(Nam: 0, Nu: 1):"<<endl;
                int inGioiTinh;
                cin >> inGioiTinh;
                GIOI_TINH = (typeGioiTinh)inGioiTinh;
                sv.setGioi_Tinh(GIOI_TINH);
                break;
            case 4:
                cout<<"Nhap diem toan:"<<endl;
                cin>> DIEM_TOAN;
                sv.setDiem_Toan(DIEM_TOAN);
                break;
            case 5:
                cout<<"Nhap diem ly:"<<endl;
                cin>> DIEM_LY;
                sv.setDiem_Ly(DIEM_LY);
                break;
            case 6:
                cout<<"Nhap diem hoa:"<<endl;
                cin>> DIEM_HOA;
                sv.setDiem_Hoa(DIEM_HOA);
                break;
            case 0:
                cout << "Ket thuc chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
    } while (choose != 0);
    }
   }
}

void xoaSinhVien(list<SinhVien>& database) {
    int ID;
    cout << "Nhap ID sinh vien can xoa: ";
    cin >> ID;

    bool ref = 0;
    for (auto it = database.begin(); it != database.end(); ++it) {
        if (it->getID() == ID) {
            database.erase(it);
            ref = 1;
            cout << "Xoa sinh vien thanh cong!" << endl;
            break;
        }
    }
    if (!ref) {
        cout << "Khong tim thay sinh vien co ID: " << ID << endl;
    }
}

int main(){
    list<SinhVien> database;

    return 0;
}