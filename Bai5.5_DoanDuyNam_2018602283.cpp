#include<iostream>
#include<string.h>
#include <iomanip>
using namespace std;
class MayGiat
{
private:
    char TenMayGiat[];
    char TenHang[];
    char Loai[];
    int KhoiLuongGiat;
public:
	MayGiat(char TenMayGiat[], char TenHang[], char Loai[], int KhoiLuongGiat);
    void xuat();
};
MayGiat::MayGiat(char TenMayGiat[], char TenHang[], char Loai[], int KhoiLuongGiat)
{
    {
        strcpy(this->TenMayGiat,TenMayGiat);
        strcpy(this->TenHang ,TenHang);
        strcpy(this->Loai,Loai);
        this->KhoiLuongGiat=KhoiLuongGiat;
    }
}
void MayGiat::xuat()
{
    cout << "THONG TIN MAY GIAT" << endl;
    cout << "Ten may giat: " << TenMayGiat << endl;
    cout << "Ten hang: " << TenHang << endl;
    cout << "Loai: " << Loai << endl;
    cout << "Khoi luong giat: " << KhoiLuongGiat << " kg" << endl;
}
class TuLanh
{
private:
    string TenTu;
    string TenHang;
    int DungTich;
    int NamSX;
public:
	TuLanh(string TenTu, string TenHang, int DungTich, int NamSX);
    void xuat();
};
TuLanh::TuLanh(string TenTu, string TenHang, int DungTich, int NamSX)
{
    this->TenTu = TenTu;
    this->TenHang = TenHang;
    this->DungTich = DungTich;
    this->NamSX = NamSX;
}
void TuLanh::xuat()
{
    cout << "THONG TIN TU LANH " << endl;
    cout << "Ten tu lanh: " << TenTu << endl;
    cout << "Ten hang: " << TenHang << endl;
    cout << "Dung tich: " << DungTich << " lit" << endl;
    cout << "Nam san xuat: " << NamSX << endl;
}
class ThucPham
{
protected:
	char TenTP[15];
	int Gia;
public:
	void Nhap()
	{
		cout<<"Nhap ten TP :";
		fflush(stdin);
		gets(TenTP);
		cout<<"Nhap gia :";
		cin >> Gia;
	}
	void Xuat()
	{
		cout<<setw(10)<<TenTP;
		cout<<setw(12)<<Gia;
	}
};
class TPHop :public ThucPham
{
private:
	int SoHop;
public:
	void Nhap()
	{
		ThucPham::Nhap();
		cout<<"Nhap so hop :";
		cin>>SoHop;
	}
	void Xuat()
	{
		ThucPham::Xuat();
		cout<<setw(10)<<SoHop<<endl;
	}
};
class TPKHop : public ThucPham
{
private:
	int KL;
public:
	void Nhap()
	{
		ThucPham::Nhap();
		cout<<"Nhap khoi luong :";
		cin>>KL;
	}
	void Xuat()
	{
		ThucPham::Xuat();
		cout<<setw(11)<<KL<<endl;
	}
};
void Hien1()
{
    cout << setw(10) << "Ten TP";
    cout << setw(12) << "Gia";
    cout << setw(10) << "So Hop" << endl;
}
void Hien2()
{
    cout << setw(10) << "Ten TP";
    cout << setw(12) << "Gia";
    cout << setw(11) << "Khoi Luong" << endl;
}
int main()
{
	TPHop x;
    TPKHop y;
    MayGiat a = MayGiat("May giat","Samsung","cua tren",8);
    a.xuat();
    TuLanh b = TuLanh("Tu lanh 1","Panasonic",200,2020);
    b.xuat();
    cout << "Nhap thong tin thuc pham co hop" << endl;
    x.Nhap();
    cout << "Nhap thong tin thuc pham khong hop" << endl;
    y.Nhap();
    cout << "Thong tin thuc pham co hop" << endl;
    Hien1();
    x.Xuat();
    cout << "Thong tin thuc pham khong hop" << endl;
    Hien2();
    y.Xuat();
	system("pause");
	return 0;
}
