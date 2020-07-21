#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class XeHoi
{
private:
    char NhanHieu[14];
    char Hang[14];
    char Dang[14];
    char MauSon[14];
    int Nam;
    char XX[14];
    int Gia;
public:
    void Nhap();
    void Xuat();
    friend void Tim(XeHoi a[], int n);
    friend void SapXep(XeHoi a[],int n);
};
void XeHoi::Nhap()
{
    cout << "Nhap Nhan Hieu :";
    fflush(stdin);
    gets(NhanHieu);
    cout << "Nhap Hang :";
    fflush(stdin);
    gets(Hang);
    cout << "Nhap Kieu Dang :";
    fflush(stdin);
    gets(Dang);
    cout << "Nhap Mau Son :";
    fflush(stdin);
    gets(MauSon);
    cout << "Nhap Xuat xu :";
    fflush(stdin);
    gets(XX);
    cout << "Nhap Nam sx :";
    cin >> Nam;
    cout << "Nhap Gia :";
    cin >> Gia;
}
void XeHoi::Xuat()
{
    cout << setw(15) << NhanHieu;
    cout << setw(15) << Hang;
    cout << setw(15) << Dang;
    cout << setw(15) << MauSon;
    cout << setw(15) << XX;
    cout << setw(5) << Nam;
    cout << setw(12) << Gia;
}
void Hien()
{
    cout << setw(4) << "STT";
    cout << setw(15) << "Nhan Hieu";
    cout << setw(15) << "Hang";
    cout << setw(15) << "Dang";
    cout << setw(15) << "MauSon";
    cout << setw(15) << "Xuat Xu";
    cout << setw(5) << "Nam";
    cout << setw(12) << "Gia" << endl;
}
void Tim(XeHoi a[], int n)
{
    int d=0;
    cout << "------------ Danh sach xe hang toyota ------------"<<endl;
    Hien();
    for (int i = 0; i < n; i++)
    {
        if (stricmp(a[i].Hang,"TOYOTA")== 0)
        {
            d++;
            cout<<setw(4)<<i;
            a[i].Xuat();
            cout<<endl;
        }
    }
    if(d==0)
        cout<<"--------------- Khong Co ---------------"<<endl;
}
void SapXep(XeHoi a[],int n)
{
    for( int i=0 ; i<n-1 ; i++)
    {
        for(int j = i+1 ; j<n; j++)
        {
            if(a[i].Gia<a[j].Gia)
            {
                XeHoi x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }
    cout << "------------ Danh sach xe sau khi sap xep ------------"<<endl;
    Hien();
    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << i + 1;
        a[i].Xuat();
        cout << endl;
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
    cout << "------------ Danh sach xe ------------"<<endl;
    Hien();
    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << i + 1;
        a[i].Xuat();
        cout << endl;
    }
    Tim(a,n);
    SapXep(a,n);
    system("pause");
    delete a;
    return 0;
}
