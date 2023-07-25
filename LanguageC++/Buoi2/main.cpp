#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DoiTuong{
    private:
        string TEN;
        int TUOI;
        string DIA_CHI;
        
    public:
        void ThemThongTin(string TEN, int TUOI, string DIA_CHI);
        void hienthi();
};
void DoiTuong::ThemThongTin(string ten, int tuoi, string dia_chi){
    TEN = ten;
    TUOI = tuoi;
    DIA_CHI = dia_chi;

}
void DoiTuong::hienthi(){
    cout<<"Ten: "<< TEN <<endl;
    cout<<"Tuoi: "<< TUOI <<endl;
    cout<<"Dia chi: "<< DIA_CHI <<endl;
}

class SinhVien : public DoiTuong{
    public:
        int MSSV;
};

int main(int argc, char const *argv[]){
    vector<int> arr = {1, 22 , 3};
    for(int i = 0; i< arr.size(); i++ ){
        cout<<arr[i]<<" "<<endl;
    }
    return 0;
}