#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class Mon
{
private:
    char TenMon[20];
    float SoTin;
    float Diem;
public:
    void Nhap()
    {
        cout<<"Nhap ten mon :";
        fflush(stdin);
        gets(TenMon);
        cout << "Nhap so tin:";
        cin >> SoTin;
        cout << " Nhap diem :";
        cin>>Diem;
    }
    void Xuat()
    {
        cout << setw(20) <<TenMon;
        cout << setw(10) <<SoTin;
        cout << setw(10) <<Diem<<endl;
    }
    friend class PhieuDiem;
    friend float DiemTB(Mon a[],int SLM);
};
class PhieuDiem
{
private:
    char MaSV[15];
    char TenSV[20];
    char Lop[10];
    int Khoa;
    int SLM;
    Mon a[100];
public:
    void Nhap()
    {
        cout <<" Nhap ma sinh vien :";
        fflush(stdin);
        gets(MaSV);
        cout<<"Nhap ten sinh vien :";
        fflush(stdin);
        gets(TenSV);
        cout<<"Sinh vien lop :";
        fflush(stdin);
        gets(Lop);
        cout<<"Nhap khoa so:";
        cin>>Khoa;
        cout << "Nhap so luong mon :";
        cin >>SLM;
        for(int i = 0; i < SLM; i++)
        {
            cout <<" Nhap mon "<< i + 1 <<endl;
            a[i].Nhap();
        }
    }
    void Xuat()
    {
        cout <<left <<setw(15) <<"Ma sinh vien:" << setw(15) << MaSV;
        cout << setw(15) <<"Ten sinh vien:" << setw(20) << TenSV << endl;
        cout <<setw(15)<<"Lop:"<<setw(15)<<Lop;
        cout << setw(5)<<"Khoa"<<setw(10)<<Khoa<<endl;
        cout << setw(20) <<"Ten Mon";
        cout << setw(10) <<"So Tin";
        cout << setw(10) << "Diem"<<endl;
        for(int i = 0; i<SLM; i++)
        {
            a[i].Xuat();
        }
        cout << right <<setw(30) << "DiemTB :";
        cout << left <<setw(10) <<setprecision(3)<<DiemTB(a,SLM)<<endl;
    }
    friend class NhaCC;
    friend float DiemTB(Mon a[],int SLM);
};
float DiemTB(Mon a[],int SLM)
{
    float x = 0,y = 0;
    for(int i = 0; i<SLM; i++)
    {
        x += a[i].Diem*a[i].SoTin;
        y +=a[i].SoTin;
    }
    return x/y;
}
int main()
{
    PhieuDiem h;
    h.Nhap();
    cout << "\t ---Phieu Bao Diem---"<<endl;
    h.Xuat();
    system("pause");
    return 0;
}
