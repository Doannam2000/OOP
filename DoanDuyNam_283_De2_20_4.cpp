#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class Sach
{
private:
    char MaSach[10];
    char TenSach[10];
    int Gia;
    int SL;
public:
    float ThanhTien()
    {
        return SL*Gia;
    }
    void Nhap()
    {
        cout<<"Nhap ma sach :";
        fflush(stdin);
        gets(MaSach);
        cout<<"Nhap ten sach :";
        fflush(stdin);
        gets(TenSach);
        cout <<"Nhap gia :";
        cin >>Gia;
        cout << " Nhap so luong :";
        cin>>SL;
    }
    void Xuat()
    {
        cout << setw(10) <<MaSach;
        cout << setw(10) << TenSach;
        cout << setw(10) << Gia;
        cout << setw(10)<< SL;
        cout << setw(10) << ThanhTien()<<endl;
    }
    friend class PhieuSach;
    friend double CongThanhTien(Sach a[],int SLS);
};
class NhaCC
{
private:
    char MaNCC[10];
    char TenNCC[30];
    char DiaChi[30];
public:
    void Nhap()
    {
        cout << "Nhap ma nha cung cap :";
        fflush(stdin);
        gets(MaNCC);
        cout << "Nhap ten nha cung cap :";
        fflush(stdin);
        gets(TenNCC);
        cout << "Nhap dia chi nha cung cap :";
        fflush(stdin);
        gets(DiaChi);
    }
    void Xuat()
    {
        cout << left << setw(10) <<"Ma NCC:"<< setw(10)<< MaNCC;
        cout << setw(10) << "Ten NCC:"<< setw(30) << TenNCC <<endl ;
        cout << setw(10) << "Dia Chi:"<< setw(30) << DiaChi << endl ;
    }
    friend class PhieuSach;
};
class PhieuSach
{
private:
    char MaPhieu[10];
    char Date[12];
    NhaCC x;
    int SLS;
    Sach a[100];
public:
    void Nhap()
    {
        cout <<"Nhap ma phieu :";
        fflush(stdin);
        gets(MaPhieu);
        cout<<"Nhap ngay lap :";
        fflush(stdin);
        gets(Date);
        x.Nhap();
        cout << "Nhap so luong sach :";
        cin >>SLS;
        for(int i = 0; i < SLS; i++)
        {
            cout <<"Nhap sach "<< i + 1 <<endl;
            a[i].Nhap();
        }
    }
    void Xuat()
    {
        cout <<left <<setw(10) <<"Ma Phieu:" << setw(10) << MaPhieu;
        cout << setw(10) <<"Ngay lap:" << setw(12) << Date << endl;
        x.Xuat();
        cout << setw(10) <<"Ma Sach";
        cout << setw(10) <<"Ten Sach";
        cout << setw(10) <<"Gia";
        cout<<setw(10)<<"So Luong";
        cout << setprecision(0) <<fixed << "ThanhTien"<<endl;
        for(int i = 0; i<SLS; i++)
        {
            a[i].Xuat();
        }
        cout << right <<setw(40) << "Tong Thanh Tien :";
        cout << left <<setprecision(0)<<fixed<<CongThanhTien(a,SLS)<<endl;
    }
    friend class NhaCC;
    friend double CongThanhTien(Sach a[],int SLS);
};
double CongThanhTien(Sach a[],int SLS)
{
    double x = 0 ;
    for(int i = 0; i<SLS; i++)
    {
        x += a[i].ThanhTien();
    }
    return x;
}
int main()
{
    PhieuSach sach;
    sach.Nhap();
    cout << "\t\t ---Phieu Nhap Sach---"<<endl;
    sach.Xuat();
    system("pause");
    return 0;
}
