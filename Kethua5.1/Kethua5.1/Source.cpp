#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class PERSON
{
protected:
	string Hoten;
	string Ngaysinh;
	string Quequan;
};
class KYSU : public PERSON
{
private:
	string Nganh;
	int NamTN;
public:
	void Nhap();
	void Xuat();
};
void KYSU::Nhap()
{
	cout << "Nhap Ho Ten :";
	cin.ignore();
	getline(cin,Hoten);
	cout << "Nhap Ngay sinh (dd/mm/yyyy) :";
	cin.ignore();
	getline(cin, Ngaysinh);
	cout << "Nhap Que quan :";
	cin.ignore();
	getline(cin, Quequan);
	cout << "Nhap Nganh :";
	cin.ignore();
	getline(cin, Nganh);
	cout << "Nhap nam tot nghiep :";
	cin >> NamTN;
}
void KYSU::Xuat()
{
	cout << left << setw(15) << Hoten;
	cout << setw(10) << Ngaysinh;
	cout << setw(10) << Quequan;
	cout << setw(6) << Nganh;
	cout << right << setw(6) << NamTN<< endl ;
}
void HienThi()
{
	cout << left << setw(2) << "STT";
	cout << setw(15) << "Ho Ten";
	cout << setw(10) << "Ngay Sinh";
	cout << setw(10) << "Que Quan";
	cout << setw(6) << "Nganh";
	cout << right << setw(6) << "Nam TN" << endl;
}
int main()
{
	int n;
	cout << "Nhap so luong ky su :";
	cin >> n;
	KYSU *a;
	a = new KYSU[n];
	cout << "\t\t================= Nhap Thong Tin Ky Su =================" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Ky Su " << i + 1 << " :"<< endl ;
		a[i].Nhap();
	}
	cout << "\t\t=================   Thong Tin Ky Su    =================" << endl;
	HienThi();
	for (int i = 0; i < n; i++)
	{
		cout << setw(2) << i + 1 ;
		a[i].Xuat();
	}
	delete a;
	system("pause");
	return 0;
}