#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class XeHoi
{
private:
	char NhanHieu[10];
	char Hang[10];
	char Dang[10];
	char MauSon[10];
	int Nam;
	char XX[10];
	int Gia;
public:
	void Nhap();
	void Xuat();
	friend void Tim(XeHoi a[], int n);
};
void XeHoi::Nhap()
{
	cout << "Nhap Nhan Hieu :";
	cin.ignore();
	gets_s>>NhanHieu;
	cout << "Nhap Hang :";
	cin.ignore();
	getline(cin, Hang);
	cout << "Nhap Kieu Dang :";
	cin.ignore();
	getline(cin, Dang);
	cout << "Nhap Mau Son :";
	cin.ignore();
	getline(cin, MauSon);
	cout << "Nhap Xuat xu :";
	cin.ignore();
	getline(cin, XX);
	cout << "Nhap Nam sx :";
	cin >> Nam;
	cout << "Nhap Gia :";
	cin >> Gia;
}
void XeHoi::Xuat()
{
	cout << setw(10) << NhanHieu;
	cout << setw(10) << Hang;
	cout << setw(10) << Dang;
	cout << setw(10) << MauSon;
	cout << setw(10) << XX;
	cout << setw(5) << Nam;
	cout << setw(12) << Gia;
}
void Hien()
{
	cout << setw(4) << "STT";
	cout << setw(10) << "Nhan Hieu";
	cout << setw(10) << "Hang";
	cout << setw(10) << "Dang";
	cout << setw(10) << "MauSon";
	cout << setw(10) << "Xuat Xu";
	cout << setw(5) << "Nam";
	cout << setw(12) << "Gia" << endl;
}
void Tim(XeHoi a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].Hang == "TOYOTA")
		{

		}
	}
}
int main()
{
	int n;
	cout << "Nhap so luong xe:";
	cin >> n;
	XeHoi* a = new XeHoi[n];
	cout << "------------ Nhap danh sach xe ------------"<<endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap xe " << i + 1 << endl;
		a[i].Nhap();
	}
	cout << "------------ Nhap danh sach xe ------------"<<endl;
	Hien();
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << i + 1;
		a[i].Xuat();
		cout << endl;
	}
	system("pause");
}