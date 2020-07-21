#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class SanPham
{
protected:
    char MaSP[10];
    char TenSP[15];
    char NgaySX[12];
    float TrongLuong;
    char MauSac[10];
public:
    void Nhap();
    void Xuat();
};
void SanPham::Nhap()
{
    cout << "Nhap ma SP: ";     
	fflush(stdin);
	gets(MaSP);
    cout << "Nhap ten SP: ";    
	fflush(stdin);  
	gets(TenSP);
    cout << "Nhap ngay san xuat: (dd/mm/yyyy)";     
	fflush(stdin);  
	gets(NgaySX);
    cout << "Nhap trong luong: ";   
	cin >> TrongLuong;
    cout << "Nhap mau sac: "; 
	fflush(stdin);  
	gets(MauSac);
}
void SanPham::Xuat()
{
    cout << setw(10) << MaSP;
    cout << setw(10) << TenSP;
    cout << setw(13) << NgaySX;
    cout << setw(15) << TrongLuong;
    cout << setw(10) << MauSac;
}

class HangDienTu: public SanPham
{
private:
    int P;
    int DongDien;
public:
    void Nhap();
    void Xuat();
    friend void TrongLuong(HangDienTu *a, int n);
};
void HangDienTu::Nhap()
{
    SanPham::Nhap();
    cout << "Nhap cong suat: "; 
	cin >> P;
	do
	{
		cout << "Nhap dong dien(1/2) :";    
		cin >> DongDien;
	}while(DongDien!=1 && DongDien!=2);
}
void HangDienTu::Xuat()
{
    SanPham::Xuat();
    cout << setw(10) << P;
    cout << setw(15) << DongDien << endl;
}

void NhapHangDienTu(HangDienTu *&a, int &n)
{
    cout << "Nhap so mat hang: "; 
	cin >> n;
    a = new HangDienTu[n];
    for(int i = 0; i < n; i++)
	{
        cout << "Nhap thong tin mat hang thu " << i + 1 << endl;
        a[i].Nhap();
    }
}
void Hien()
{
    cout << setw(10) << "Ma SP";
    cout << setw(10) << "Ten SP";
    cout << setw(13) << "Ngay SX";
    cout << setw(15) << "Trong Luong";
    cout << setw(10) << "Mau Sac";
    cout << setw(10) << "Cong Suat";
    cout << setw(15) << "Dong Dien" << endl;
}

void XuatHangDienTu(HangDienTu *a, int n)
{
    for(int i = 0; i < n; i++)
	{
        a[i].Xuat();
    }
}
void TrongLuong(HangDienTu *a, int n)
{
    float Min = a[0].TrongLuong;
    for(int i = 1; i < n; i++)
	{
        if(a[i].TrongLuong < Min)
		{
            Min = a[i].TrongLuong;
        }
    }
    Hien();
    for(int i = 0; i < n; i++)
	{
        if(a[i].TrongLuong == Min)
		{
            a[i].Xuat();
        }
    }
}
int main()
{
    HangDienTu *a;
    int n;
    NhapHangDienTu(a,n);
    cout << "Nhap danh sach hang dien tu" << endl;
    Hien();
    XuatHangDienTu(a,n);
    cout << "Danh sach hang dien tu co trong luong nho nhat" << endl;
    TrongLuong(a,n);
    return 0;
}
