#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class CSSP
{
protected:
    char TenSP[10];
    int NamSX;
    long Gia;
public:
    void Nhap();
    void Xuat();
};
void CSSP::Nhap()
{
    cout<<"Nhap ten sp :";
    fflush(stdin);
    gets(TenSP);
    cout<<"Nhap nam san xuat :";
    cin>>NamSX;
    cout<<"Nhap gia :";
    cin >> Gia;
}
void CSSP::Xuat()
{
    cout<<setw(10)<<TenSP;
    cout<<setw(6)<<NamSX;
    cout<<setw(10)<<Gia;
}
class HoaDon : public CSSP
{
public:
    int SLB;
    long GiaBan;
public:
    void Nhap();
    void Xuat();
    long TinhTien()
    {
        return SLB * GiaBan;
    }
    long Thue()
    {
        return (TinhTien()*0.1);
    }
    long lai()
    {
        return (GiaBan - Gia)*SLB;
    }
};
void HoaDon::Nhap()
{
    cout<<"Nhap thong tin san pham "<<endl;
    CSSP::Nhap();
    cout<<"Nhap so luong ban :";
    cin >>SLB;
    cout<<"Nhap gia ban :";
    cin>>GiaBan;
}
void HoaDon::Xuat()
{
    CSSP::Xuat();
    cout<<setw(7)<<SLB;
    cout<<setw(10)<<Gia;
}
void Hien()
{
    cout<<setw(4)<<"STT";
    cout<<setw(10)<<"Ten SP";
    cout<<setw(6)<<"NamSX";
    cout<<setw(10)<<"Gia";
    cout<<setw(7)<<"SL";
    cout<<setw(10)<<"Gia Ban"<<endl;
}
void Xuat(HoaDon a[],int n)
{
    Hien();
    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << i + 1;
        a[i].Xuat();
        cout << endl;
    }
}
void SX(HoaDon a[],int n)
{
    for(int i = 0 ; i<n - 1; i++)
    {
        for(int j = i ; j<n; j++ )
        {
            if(a[i].lai() < a[j].lai())
            {
                HoaDon x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }
    cout<<"-------------- Danh sach sau khi sap xep --------------"<<endl;
    Xuat(a,n);
}
long Tong(HoaDon a[],int n)
{
    long x;
    for(int i =0; i<n; i++)
    {
        x += a[i].TinhTien();
    }
    return x;
}
void Thue(HoaDon a[],int n)
{
    long max = a[0].Thue();
    for(int i = 0 ; i <n; i++)
    {
        if(a[i].Thue() > max)
            max = a[i].Thue();
    }
    cout<<"Hoa don ban san phan co tien thue cao nhat la "<<endl;
    int d =0;
    Hien();
    for(int i= 0 ; i<n; i++)
    {
        if(a[i].Thue() == max)
        {
            d++;
            cout<<setw(4)<<d;
            a[i].Xuat();
            cout<<endl;
        }
    }
}
int main()
{
    int n;
    cout << "Nhap so luong hoa don:";
    cin >> n;
    HoaDon*a = new HoaDon[n];
    cout << "------------ Nhap danh Hoa Don ------------"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap Hoa Don " << i + 1 <<endl;
        a[i].Nhap();
    }
    cout << "------------ Danh sach Hoa Don ------------"<<endl;
    Xuat(a,n);
    SX(a,n);
    cout << "Tong tien cua cac hoa don = "<<Tong(a,n)<<endl;
    Thue(a,n);
    system("pause");
    delete a;
    return 0;
}
