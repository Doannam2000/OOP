#include<bits/stdc++.h>
using namespace std;
class sinhvien;
class date
{
	private:
		int day;
		int month;
		int year;
	public:
		friend class sinhvien;
		friend void y_b(sinhvien a[],int n);
};
class sinhvien
{
	private:
		char masv[20];
		int diemt,dieml;
		char tensv[20];
		date n;
	public:
		void nhap();
		void xuat();
		friend class date;
	friend void dsnhap(sinhvien a[],int n);
	friend void dsxuat(sinhvien a[],int n);
	friend void y_a(sinhvien a[],int n);
	friend void y_b(sinhvien a[],int n);
	friend void y_c(sinhvien a[],int n);
	friend void y_d(sinhvien a[],int n);
	
};
void sinhvien::nhap()
{
	cout<<"\nnhap ma sinh vien: ";fflush(stdin);gets(masv);
	cout<<"nhap ten sinh vien: ";fflush(stdin);gets(tensv);
	cout<<"Ngay sinh";cin>>n.day;cout<<"thang: ";cin>>n.month;cout<<"nam: ";cin>>n.year;
	cout<<"diem mon toan: ";cin>>diemt;
	cout<<"diem mon toan: ";cin>>dieml;
}
void sinhvien::xuat()
{
	cout<<"ma sinh vien: "<<masv;
	cout<<"ten sinh vien: "<<tensv;
	cout<<"ngay sinh: "<<n.day<<"/"<<n.month<<"/"<<n.year;
	cout<<"diem toan: "<<diemt;
	cout<<"diem li: "<<dieml<<endl;
}
void dsnhap(sinhvien a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\nhap vafo thong tin sinh vien thu "<<i+1<<endl;
		a[i].nhap();
	}
}
void dsxuat(sinhvien a[],int n)
{
	cout<<setw(15)<<"Ma sv";
	cout<<setw(15)<<"Ten sv";
	cout<<setw(20)<<"Ngay sinh";
	cout<<setw(15)<<"diem toan";
	cout<<setw(15)<<"diem li";
	for(int i=0;i<n;i++)
	{
		a[i].xuat();
	}
}
void y_a(sinhvien a[],int n)
{
	int min=a[1].diemt+a[1].dieml;
	for(int i=1;i<n;i++)
	{
		if((a[i].diemt+a[i].dieml)<min)
		min=(a[i].diemt+a[i].dieml);
		a[i].xuat();
	}
	
}
void y_b(sinhvien a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i].n.day==30  &&   a[i].n.month==4);
		a[i].xuat();
	}
}
void y_c(sinhvien a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(strcmp(a[i].tensv,a[i+1].tensv)<0)
		char tam=a[i].tensv;
		a[i].tensv=a[i+1].tensv;
		a[i+1].tensv=tam;	
	}
	dsxuata(a,n);	
}
void y_d(sinhvien a[],int n)
{
	cout<<setw(15)<<"Ma sv";
	cout<<setw(15)<<"Ten sv";
	cout<<setw(20)<<"Ngay sinh";
	cout<<setw(15)<<"diem toan";
	cout<<setw(15)<<"diem li";
	for(int i=0;i<n;i++)
	{
		if(a[i].ngaysinh.year!=1998).a[i].xuat();
	}
}
int main()
{
	int a[100];
	int n;
	cout<<"\Nhap so sinh vien can khai bao: ";cin>>n;
	dsnhap(a,n);
	dsxuat(a,n);
	y_a(a,n);
	y_b(a,n);
	y_c(a,n);
	y_d(a,n);
	return 0;
}
