#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

class SinhVien
{
protected:
    char HoTen[30];
    int SBD;
public:
    void Nhap();
    void Xuat();
};
void SinhVien::Nhap()
{
    cout << "Nhap ho ten sinh vien: "; 
	 fflush(stdin);  
	 gets(HoTen);
    cout << "So bao danh: ";    
	cin >> SBD;
}

void SinhVien::Xuat()
{
    cout << setw(15) << HoTen;
    cout << setw(10) << SBD;
}

class DiemThi:public SinhVien
{
protected:
    float KQ1, KQ2;
public:
    void Nhap();
    void Xuat();
};

void DiemThi::Nhap()
{
    SinhVien::Nhap();
    cout << "Nhap ket qua 1: ";     
	cin >> KQ1;
    cout << "Nhap ket qua 2: ";     
	cin >> KQ2;
}

void DiemThi::Xuat()
{
    SinhVien::Xuat();
    cout << setw(5) << KQ1;
    cout << setw(5) << KQ2;
}

class KetQua:public DiemThi
{
public:
    float TinhTong();
};
float KetQua::TinhTong()
{
    return DiemThi::KQ1 + DiemThi::KQ2;
}

void Nhap(KetQua *&a, int &n)
{
    cout << "Nhap so sinh vien: ";  cin >> n;
    a = new KetQua[n];
    for(int i = 0; i < n; i++)
	{
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        a[i].Nhap();
    }
}

void Xuat(KetQua *a, int n)
{
    for(int i = 0; i < n; i++)
	{
        a[i].Xuat();
        cout << setw(10) << a[i].TinhTong() << endl;
    }
}
void Hien()
{
    cout << setw(15) << "Ho Ten";
    cout << setw(10) << "SBD";
    cout << setw(5) << "KQ1";
    cout << setw(5) << "KQ2";
    cout << setw(10) << "Tong" << endl;
}

int main()
{
    KetQua *a;
    int n;
    Nhap(a,n);
    cout << "Danh Sach KQ" << endl;
    Hien();
    Xuat(a,n);
    return 0;
}
