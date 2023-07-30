#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include "../Header/SinhVien.hpp"
#include <cassert>
#include <cstring> // Thêm thư viện để sử dụng hàm strcmp()

using namespace std;

bool Gioi_Tinh_Hop_Le(char gioi_tinh){
    return (gioi_tinh == 'NAM'|| gioi_tinh == 'NU');
}

void ThemSinhVien(){

    string Ten;
    int id, Tuoi;
    char gioi_tinh;
    double diem_toan, diem_ly, diem_hoa;

    cin.ignore();
    cout << "Nhap ten sinh vien: ";
    getline(cin, Ten);

    cout << "Nhap gioi tinh (NAM/NU): ";
    cin >> gioi_tinh;

    cout << "Nhap tuoi sinh vien: ";
    cin >> Tuoi;

    cout << "Nhap diem Toan: ";
    cin >> diem_toan;

    cout << "Nhap diem Ly: ";
    cin >> diem_ly;

    cout << "Nhap diem Hoa: ";
    cin >> diem_hoa;

    assert(!Ten.empty() && "Ten khong duoc de trong");
    if (!Gioi_Tinh_Hop_Le(gioi_tinh)) {
        assert("Gioi tinh nhap sai");
    }
    assert( 17< Tuoi <100 && "Tuoi phai lon hon 17");
    assert(0 <= diem_toan <= 10 && "Diem toan phai giua 0 va 10");
    assert(0 <= diem_ly <= 10 && "Diem ly phai giua 0 va 10");
    assert(0 <= diem_hoa <= 10 && "Diem hoa phai giua 0 va 10");

    SinhVien ThemSinhVien( string Ten, int Tuoi, char gioi_tinh, double diem_toan,double diem_ly, double diem_hoa);

}

void updateSinhVien() {
   
}