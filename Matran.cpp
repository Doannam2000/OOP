#include<iostream>
#include<fstream>

using namespace std;

class Matran
{
private:
	int a[100][100];
	int n;	
public:
	Matran()
	{
		n = 2;
	}
	friend istream &operator>>(istream &is,Matran &x);
	friend ostream &operator<<(ostream &os,Matran x);
	Matran operator+(Matran x)
	{
		Matran a;
		for(int i = 0 ;i<x.n;i++)
			for(int j = 0;j<x.n;j++)
			{
				a.a[i][j]= this->a[i][j]+x.a[i][j];
			}
		return a;
	}	
	Matran operator-(Matran x)
	{
		Matran a;
		for(int i = 0 ;i<x.n;i++)
			for(int j = 0;j<x.n;j++)
			{
				a.a[i][j]= this->a[i][j]-x.a[i][j];
			}
		return a;
	}	
};
istream &operator>>(istream &is,Matran &x)
{
	cout<<"Nhap n :";	
	do
	{
		is>>x.n;
		if(x.n<=0) 
			cout<<"Nhap lai"<<endl;
	}while(x.n<=0);
	for(int i = 0 ;i<x.n;i++)
		for(int j = 0 ;j<x.n;j++)
		{
			cout<<"nhap a["<<i<<"]["<<j<<"]:";
			is>>x.a[i][j];
		}
	return is;
}
ostream &operator<<(ostream &os,Matran x)
{
	for(int i = 0 ;i<x.n;i++)
	{
		for(int j = 0 ;j<x.n;j++)
		{
			os<<x.a[i][j]<<"\t";
		}
		cout<<endl;
	}
	return os;
}
int main()
{
	Matran a,b;
	cin>>a;
	cin>>b;
	cout<<a-b;
	return 0;
}


