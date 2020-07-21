#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class XeHoi;
class Date
{
private:
	int d;
	int m;
	int y;
public:
	friend class XeHoi;
	friend void NamSX(XeHoi a[],int n);
};
class XeHoi
{
private:
	char NhanHieu[15];
	char HangSX[15];
	Date Nam;
	int Gia;
	char XuatXu[15];
	int SLB;
public:
	void Nhap()
	{
		cout << "Nhap nhan hieu :";		fflush(stdin);		gets(NhanHieu);
		cout << "Nhap hang sx :";		fflush(stdin);		gets(HangSX);
		cout<<"Nhap nam sx"<<endl;
		cout<<"Nhap ngay :"; 			cin>>Nam.d;
		cout<<"Nhap thang :"; 			cin>>Nam.m;
		cout<<"Nhap nam :"; 			cin>>Nam.y;
		cout << "Nhap so gia ban :";	cin>>Gia;
		cout << "Nhap Xuat Xu :";		fflush(stdin);		gets(XuatXu);
		cout << "Nhap so luong ban :";	cin>>SLB;	
	}
	void Xuat()
	{
		cout << setw(15) << NhanHieu;
		cout << setw(15) << HangSX;
		cout << setw(3) << right << Nam.d << "/"<< setw(2) << Nam.m << "/"<< setw(4) << Nam.y;
		cout << setw(15) << Gia;
		cout << setw(15) << XuatXu;
		cout << setw(10) << SLB ;
		cout << setw(10) << ThanhTien() <<endl;
	}
	long ThanhTien()
	{
		return Gia*SLB;
	}
	friend void NamSX(XeHoi a[],int n);
	friend void SX(XeHoi a[],int n);
	friend void Sua(XeHoi a[] , int n);
	friend void Tong(XeHoi a[],int n);
};
void Hien()
{
		cout << setw(15) << "Nhan Hieu";
		cout << setw(15) << "Hang SX";
		cout << setw(11) << "Nam SX" ;
		cout << setw(15) << "Gia";
		cout << setw(15) << "Xuat Xu";
		cout << setw(10) << "SLB" ;
		cout << setw(10) << "ThanhTien"<<endl;
}
void NamSX(XeHoi a[],int n)
{
	int N = a[0].Nam.y;
	for(int i =0 ;i<n ;i++)
	{
		if(N < a[i].Nam.y)
		{
			N=a [i].Nam.y;
		}
	}
	cout<<"\t\t -----Thong tin xe hoi co moi ra mat------"<<endl;
	Hien();
	for(int i = 0;i<n;i++)
	{
		if(a[i].Nam.y==N)
		{
			a[i].Xuat();
		}
	}
}
void SX(XeHoi a[],int n)
{
	for(int i =0 ;i<n -1 ;i++)
	{
		for(int j = i ;j<n;j++)
		{
			if(a[i].ThanhTien()>a[j].ThanhTien())
			{
				
				XeHoi x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
		}
	}
	cout<<"\t\t -----Thong tin xe hoi sau khi SX ------"<<endl;
	Hien();
	for(int i = 0;i<n;i++)
	{
			a[i].Xuat();
	}
}
void Sua(XeHoi a[],int n)
{
	int d =0;
	char Nha[15];
	cout << " Nhap nhan hieu can sua thong tin :"; fflush(stdin); gets(Nha);
	for(int i = 0;i<n;i++)
	{
		if(stricmp(a[i].NhanHieu,Nha)==0)
		{
			cout << "Thong tin cu :" <<endl;
			Hien();
			a[i].Xuat();
			cout <<"Nhap thong tin moi" << endl;
			a[i].Nhap();
			d++;
		}
	}
	if(d!=0)
	{
		cout<<"\t\t -----Thong tin xe hoi sau khi sua thong tin ------"<<endl;
		Hien();
		for(int i = 0;i<n;i++)
		{
			a[i].Xuat();
		}
	}
	else
	{
		cout <<"Khong co"<<endl;
	}
}
void Tong(XeHoi a[],int n)
{
	int T =0 ,d =0;
	for(int i = 0;i<n;i++)
	{
		if(a[i].Gia<5100)
		{
			T += a[i].ThanhTien();
			d++;
		}
	}
	if(d== 0)
		cout <<"Khong co xe nao < 5100"<<endl;
	else
		cout <<"Tong xe hoi co gia < 5100 = "<<T <<endl;
}
int main()
{
	int n;
	cout <<"Nhap so luong xe hoi :";
	cin >> n;
	XeHoi *a = new XeHoi[n];
	cout<<"\t\t -----Nhap thong tin xe hoi------"<<endl;
	for(int i = 0;i<n;i++)
	{
		cout << "Nhap thong tin xe "<< i +1 <<endl;
		a[i].Nhap();
	}
	cout<<"\t\t -----Thong tin xe hoi------"<<endl;
	Hien();
	for(int i = 0;i<n;i++)
	{
		a[i].Xuat();
	}
	NamSX(a,n);
	SX(a,n);
	Sua(a,n);
	Tong(a,n);
	system("pause");
	return 0;
}
