#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class NgaySinh
{
private:
	int ngay,thang,nam;
public:
	friend class PERSON;
	friend class CAUTHU;
};
class PERSON
{
protected:
	char Hoten[50];
	char QueQuan[100];
	NgaySinh x;
};
class VANDONGVIEN :public PERSON
{
protected:
	char BoMon[30];
	float Thunhap;
};
void hien()
{
		cout<<setw(15)<<"Hoten";
		cout<<setw(11)<<"NgaySinh";
		cout<<setw(15)<<"QueQuan";
		cout<<setw(15)<<"BoMon";
		cout<<setw(15)<<"Thunhap";
		cout<<setw(15)<<"CLB";
		cout<<setw(15)<<"Vitri"<<endl;
}
class CAUTHU : public VANDONGVIEN
{
private:
	char CLB[100];
	char Vitri[100];
public:
	void Nhap()
	{
		cout<<"Nhap ho ten :";
		fflush(stdin);
		gets(Hoten);
		cout<<"Nhap que quan :";
		fflush(stdin);
		gets(QueQuan);
		cout<<"Nhap ngay sinh :";
		cin >>x.ngay;
		cout<<"Nhap thang sinh :";
		cin >>x.thang;
		cout<<"Nhap nam sinh :";
		cin >>x.nam;
		cout<<"Nhap Bo Mon :";
		fflush(stdin);
		gets(BoMon);
		cout<<"Nhap thu nhap :";
		cin>>Thunhap;
		cout<<"Nhap CLB :";
		fflush(stdin);
		gets(CLB);
		cout<<"Nhap Vi tri :";
		fflush(stdin);
		gets(Vitri);
	}
	void Xuat()
	{
		cout<<setw(15)<<Hoten;
		cout<<setw(3)<<x.ngay<<"/"<<setw(2)<<x.thang<<"/"<<setw(4)<<x.nam;
		cout<<setw(15)<<QueQuan;
		cout<<setw(15)<<BoMon;
		cout<<setw(15)<<Thunhap;
		cout<<setw(15)<<CLB;
		cout<<setw(15)<<Vitri<<endl;
	}
	friend void Tim(CAUTHU a[],int n);
	friend void Sua(CAUTHU a[],int n);
	
};
void Tim(CAUTHU a[],int n)
{
	int d =0;
	cout<<"Thong tin cau thu cua clb T&T"<<endl;
	hien();
	for(int i = 0 ;i<n;i++)
	{
		if(stricmp(a[i].CLB,"T&T")==0)
		{
			d=1;
			a[i].Xuat();
		}
	}
	if(d==0)
		cout<<"Khong co cau thu nao"<<endl;
}
void Sua(CAUTHU a[],int n)
{
	cout<<"Nhap ten cau thu can sua :";
	char ten[15];
	fflush(stdin);
	gets(ten);
	for(int i = 0 ;i<n;i++)
	{
		if(stricmp(a[i].Hoten,ten)==0)
		{
			strcpy(a[i].Hoten,"Ditmemay");
		}
	}
	cout<<"Thong tin cau thu "<<endl;
	hien();
	for(int i = 0;i<n;i++)
	{
		a[i].Xuat();
	}
}
int main()
{
	int n;
	cout<<"Nhap so luong cau thu :";
	do
	{
		cin >> n;
		if(n<=0||n>=50)
			cout<<"Nhap lai :";
	}while(n<=0||n>=50);
	CAUTHU *a = new CAUTHU[n];
	cout<<"Nhap thong tin cau thu "<<endl;
	for(int i = 0;i<n;i++)
	{
		cout<<"Nhap thong tin cau thu so "<<i + 1<<endl;
		a[i].Nhap();
	}
	cout<<"Thong tin cau thu "<<endl;
	hien();
	for(int i = 0;i<n;i++)
	{
		a[i].Xuat();
	}
	Tim(a,n);
	Sua(a,n);
	return 0;
}
