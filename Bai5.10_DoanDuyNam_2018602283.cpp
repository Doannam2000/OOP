#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;
class Chung
{
protected:
    char MaCB[10];
    char MaDV[10];
    int NS;
    int HeSoLuong;
    int PhuCapCa;
    int BaoHiem;
    int LCB;
public:
    void Nhap();
    void Xuat();
};
void Chung::Nhap()
{
    cout<<"Nhap ma can bo: ";
    fflush(stdin);
    gets(MaCB);
    cout<<"Nhap ma don vi: ";
    fflush(stdin);
    gets(MaDV);
    cout<<"Nhap nam sinh: ";
    cin>>NS;
    cout<<"Nhap he so luong : ";
    cin>>HeSoLuong;
    cout<<"Nhap phu cap an ca: ";
    cin>>PhuCapCa;
    cout<<"Nhap bao hiem: ";
    cin>>BaoHiem;
    cout<<"nhap luong co ban: ";
    cin>>LCB;
}
void Chung::Xuat()
{
    cout<<setw(10)<<MaCB;
    cout<<setw(10)<<MaDV;
    cout<<setw(5)<<NS;
    cout<<setw(10)<<HeSoLuong;
    cout<<setw(10)<<PhuCapCa;
    cout<<setw(12)<<LCB;
}
class CB:public Chung
{
public:
    void Nhap();
    void Xuat();
    int TinhLuong();
};
void CB::Nhap()
{
    Chung::Nhap();
}
void CB::Xuat()
{
    Chung::Xuat();
}
int CB::TinhLuong()
{
    return HeSoLuong*LCB + PhuCapCa-BaoHiem;
}
class GV:public Chung
{
private:
    int PhuCapDungLop;
    int PhuCapDocHai;
public:
    void Nhap();
    void Xuat();
    int TinhLuong();
};
void GV::Nhap()
{
    Chung::Nhap();
    do
    {
        cout<<"Moi truong co doc hai khong \n1.Co \n 2.Khong \n";
        cin>>PhuCapDocHai;
    }
    while(PhuCapDocHai!=1 && PhuCapDocHai!=2);
}
void GV::Xuat()
{
    Chung::Xuat();
    cout<<setw(10)<<LCB*0.25;
    if(PhuCapDocHai=1)
        cout<<setw(10)<<LCB*0.1;
    else
        cout<<setw(10)<<0;
}
int GV::TinhLuong()
{
    return HeSoLuong*LCB + PhuCapCa-BaoHiem + PhuCapDocHai + PhuCapDungLop*0.25;
}

void Hien(int x)
{
    cout<<setw(4)<<"STT";
    cout<<setw(10)<<"MaCb";
    cout<<setw(10)<<"MaDv";
    cout<<setw(5)<<"Nam";
    cout<<setw(10)<<"HeSoLuong";
    cout<<setw(10)<<"PCCa";
    cout<<setw(12)<<"LuongCoBan";
    if(x==1)
    {
        cout<<setw(10)<<"PCDocHai";
        cout<<setw(10)<<"PCDungLop";
    }
    cout<<setw (15)<<"Luong"<<endl;
}
void Thue(CB a[],GV b[],int n,int m)
{
    cout << "------------ Danh sach Can Bo dong thue thu nhap ------------"<<endl;
    Hien(2);
    int d =0;
    for (int i = 0; i < n; i++)
    {
        if(a[i].TinhLuong()>5000000)
        {
            d++;
            cout << setw(4) << d ;
            a[i].Xuat();
            cout<<setw(15)<<a[i].TinhLuong();
            cout << endl;
        }
    }
    if(d==0)
        cout<<"-------------------- KHONG CO -------------------"<<endl;
    d = 0;
    cout << "------------ Danh sach Giang Vien dong thue thu nhap ------------"<<endl;
    Hien(1);
    for (int i = 0; i < m; i++)
    {
        if(b[i].TinhLuong()>5000000)
        {
            d++;
            cout << setw(4) << d ;
            b[i].Xuat();
            cout<<setw(15)<<b[i].TinhLuong();
            cout << endl;
        }
    }
    if(d==0)
        cout<<"-------------------- KHONG CO -------------------"<<endl;
}
int main()
{
    int n,m;
    cout << "Nhap so luong Can Bo:";
    cin >> n;
    CB*a = new CB[n];
    cout << "------------ Nhap danh Can Bo ------------"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap Can Bo " << i + 1 <<endl;
        a[i].Nhap();
    }
    cout << "Nhap so luong Giang Vien :";
    cin>>m;
    GV*b = new GV[n];
    cout << "------------ Nhap danh Giang Vien ------------"<<endl;
    for (int i = 0; i < m; i++)
    {
        cout << "Nhap Giang Vien " << i + 1 <<endl;
        b[i].Nhap();
    }
    cout << "------------ Danh sach Can Bo ------------"<<endl;
    Hien(2);
    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << i + 1;
        a[i].Xuat();
        cout<<setw(15)<<a[i].TinhLuong();
        cout << endl;
    }
    cout << "------------ Danh sach GV ------------"<<endl;
    Hien(1);
    for (int i = 0; i < m; i++)
    {
        cout << setw(4) << i + 1;
        b[i].Xuat();
        cout<<setw(15)<<b[i].TinhLuong();
        cout << endl;
    }
    Thue(a,b,n,m);
    system("pause");
    return 0;
}

