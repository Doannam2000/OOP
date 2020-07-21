#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class Hang
{
private:
    char TenHang[10];
    float DonGia;
    int SL;
public:
    float ThanhTien()
    {
        return SL*DonGia;
    }
    void Nhap()
    {
        cout<<"Nhap ten hang :";
        fflush(stdin);
        gets(TenHang);
        cout << "Nhap don gia :";
        cin >> DonGia;
        cout << " Nhap so luong :";
        cin>>SL;
    }
    void Xuat()
    {
        cout << setw(10) <<TenHang;
        cout << setw(10) <<DonGia;
        cout << setw(10) << SL;
        cout << setw(10) << ThanhTien()<<endl;
    }
    friend class PhieuHang;
    friend float CongThanhTien(Hang a[],int SLH);
};
class NhaCC
{
private:
    char MaNCC[10];
    char TenNCC[15];
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
        cout << setw(10) << "Ten NCC:"<< setw(15) << TenNCC <<endl ;
        cout << setw(10) << "Dia Chi:"<< setw(30) << DiaChi << endl ;
    }
    friend class PhieuHang;
};
class PhieuHang
{
private:
    char MaPhieu[10];
    char Date[12];
    NhaCC x;
    int SLH;
    Hang a[100];
public:
    void Nhap()
    {
        cout <<" Nhap ma phieu :";
        fflush(stdin);
        gets(MaPhieu);
        cout<<"Nhap ngay lap :";
        fflush(stdin);
        gets(Date);
        x.Nhap();
        cout << "Nhap so luong hang :";
        cin >>SLH;
        for(int i = 0; i < SLH; i++)
        {
            cout <<" Nhap hang "<< i + 1 <<endl;
            a[i].Nhap();
        }
    }
    void Xuat()
    {
        cout <<left <<setw(10) <<"Ma Phieu:" << setw(10) << MaPhieu;
        cout << setw(10) <<"Ngay lap:" << setw(12) << Date << endl;
        x.Xuat();
        cout << setw(10) <<"TenHang";
        cout << setw(10) <<"DonGia";
        cout << setw(10) << "SoLuong";
        cout << setw(10) << "ThanhTien"<<endl;
        for(int i = 0; i<SLH; i++)
        {
            a[i].Xuat();
        }
        cout << right <<setw(30) << "Tong Thanh Tien :";
        cout << left <<setw(10) <<CongThanhTien(a,SLH)<<endl;
    }
    friend class NhaCC;
    friend float CongThanhTien(Hang a[],int SLH);
};
float CongThanhTien(Hang a[],int SLH)
{
    float x;
    for(int i = 0; i<SLH; i++)
    {
        x += a[i].ThanhTien();
    }
}
int main()
{
    PhieuHang h;
    h.Nhap();
    cout << "\t ---Phieu Nhap Hang---"<<endl;
    h.Xuat();
    system("pause");
    return 0;
}
