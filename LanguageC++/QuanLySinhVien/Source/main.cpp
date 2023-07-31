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

typeHocLuc SinhVien::getHoc_Luc(){
            if(getDiemTB()>= 8){
                return GIOI;
            }else if(getDiemTB() >=6.5 ){
                return KHA;
            }else if(getDiemTB()>= 5){
                return TRUNG_BINH;
            }else{ 
                return YEU;
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

bool Compare (const char arr1[], const char arr2[]){
    for (int i = 0; arr1[i] !='0' || arr2[i] != '\0'; i++ ){
    if ((arr1[i] - arr2[i]) > 0){
        return true;
    } else if ((arr1[i] - arr2[i]) < 0){
      return false;
    } else {
      return true;
    }
    }   
}

typeGioiTinh convertToGioiTinh(const string &GioiTinhStr){
    if(GioiTinhStr == "Nam"){
        return NAM;
    } else if (GioiTinhStr == "Nu") {
        return NU;
    }
}

void SapXepSinhVien(SinhVien &sv1, SinhVien &sv2){

    //sap xep TEN
    string tempTen = sv1.getTen();
    sv1.setTen(sv2.getTen());
    sv2.setTen(tempTen);

    //sap xep Tuoi
    int tempTuoi = sv1.getTuoi();
    sv1.setTuoi(sv2.getTuoi());
    sv2.setTuoi(tempTuoi);

    // sap xep GIOI_TINH
    string tempGioiTinhStr = sv1.getGioi_Tinh();
    typeGioiTinh tempGioiTinh = convertToGioiTinh(tempGioiTinhStr);
    sv1.setGioi_Tinh(convertToGioiTinh(sv2.getGioi_Tinh()));
    sv2.setGioi_Tinh(tempGioiTinh);

    // sap xep DIEM_TOAN
    double tempDiemToan = sv1.getDiem_Toan();
    sv1.setDiem_Toan(sv2.getDiem_Toan());
    sv2.setDiem_Toan(tempDiemToan);

    // sap xep DIEM_LY
    double tempDiemLy = sv1.getDiem_Ly();
    sv1.setDiem_Ly(sv2.getDiem_Ly());
    sv2.setDiem_Ly(tempDiemLy);

    // sap xep DIEM_HOA
    double tempDiemHoa = sv1.getDiem_Hoa();
    sv1.setDiem_Hoa(sv2.getDiem_Hoa());
    sv2.setDiem_Hoa(tempDiemHoa);

}

void sapXepTheoTen(list<SinhVien>& database) {
    for (auto it = database.begin(); it != database.end(); it++)
    {
        for (auto it2 = std::next(it); it2 != database.end(); it2++)
        {
            if (Compare(it->getTen().c_str(), it2->getTen().c_str()))
            {
                 SapXepSinhVien(*it, *it2);
            }
            
        }
        
    }
    
}

void hienThiDanhSachSinhVien(list<SinhVien>& database) {
    cout << "Danh sach sinh vien:" << endl;
    for (auto& sv : database) {
        cout << "ID: " << sv.getID() << ", Ten: " << sv.getTen() << ", Tuoi: " << sv.getTuoi()<<", Gioi Tinh: "<<sv.getGioi_Tinh() 
             << ", Diem toan: " << sv.getDiem_Toan() << ", Diem ly: " << sv.getDiem_Ly()
             << ", Diem hoa: " << sv.getDiem_Hoa() << ", Diem trung binh: " << sv.getDiemTB()
             << ", Hoc luc: ";
        switch (sv.getHoc_Luc()) {
            case GIOI:
                cout << "Gioi";
                break;
            case KHA:
                cout << "Kha";
                break;
            case TRUNG_BINH:
                cout << "Trung binh";
                break;
            case YEU:
                cout << "Yeu";
                break;
            default:
                cout << "N/A";
                break;
        }
        cout << endl;
    }
}

int main(){
    list<SinhVien> database;
 int choice;
    do {
        cout << "\n------- Menu -------" << endl;
        cout << "1. Them sinh vien" << endl;
        cout << "2. Cap nhat thong tin sinh vien" << endl;
        cout << "3. Xoa sinh vien" << endl;
        cout << "4. Hien thi danh sach sinh vien" << endl;
        cout << "5. Sap xep sinh vien theo ten" << endl;
        cout << "6. Tim kiem sinh vien theo ten" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ThemSinhVien(database);
                break;
            case 2:
                updateSinhVien(database);
                break;
            case 3:
                xoaSinhVien(database);
                break;
            case 4:
                hienThiDanhSachSinhVien(database);
                break;
            case 5:
                sapXepTheoTen(database);
                cout << "Sap xep sinh vien theo ten thanh cong!" << endl;
                break;
            case 6: {
                string ten;
                cout << "Nhap ten sinh vien can tim: ";
                cin.ignore();
                getline(cin, ten);
                list<SinhVien> result;
                for ( auto& sv : database) {
                    if (sv.getTen() == ten) {
                        result.push_back(sv);
                    }
                }
                if (result.empty()) {
                    cout << "Khong tim thay sinh vien co ten: " << ten << endl;
                } else {
                    hienThiDanhSachSinhVien(result);
                }
                break;
            }
            case 0:
                cout << "Ket thuc chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}