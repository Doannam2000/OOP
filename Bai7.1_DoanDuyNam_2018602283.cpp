#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class NSX
{
private:
    char TenNSX[15];
    char DiaChi[15];
public:
    void Nhap()
    {
        cout << "Nhap ma nha san xuat :";
        fflush(stdin);
        gets(TenNSX);
        cout << "Nhap dia chi nha cung cap :";
        fflush(stdin);
        gets(DiaChi);
    }
    void Xuat()
    {
        cout << setw(15) << TenNSX;
        cout << setw(15) << DiaChi;
    }
    friend class Hang;
};
class Hang
{
protected:
    char TenHang[10];
    NSX x;
    int DonGia;
public:
    void Nhap()
    {
        cout<<"Nhap ten hang :";
        fflush(stdin);
        gets(TenHang);
        cout << "Nhap thong tin nha san xuat"<<endl;
        x.Nhap();
        cout << " Nhap don gia :";
        cin>>DonGia;
    }
    void Xuat()
    {
        cout << setw(15) <<TenHang;
        x.Xuat();
        cout << setw(10) << DonGia;
    }
    Hang()
    {
        strcpy(TenHang,"LG-2703");
        strcpy(x.TenNSX,"LG");
        strcpy(x.DiaChi,"Ha Noi");
        DonGia = 15000000;
    }
};
class Date
{
private:
    int D;
    int M;
    int Y;
public:
    void Nhap()
    {
        cout << "Nhap ngay :";
        cin >>D;
        cout << "Nhap thang :";
        cin >>M;
        cout << "Nhap nam :";
        cin >>Y;
    }
    void Xuat()
    {
        cout <<setw(3) <<D;
        cout <<"/"<<setw(2) <<M;
        cout <<"/"<<setw(4)<<Y << endl;
    }
    friend class Tivi;
};
class Tivi : public Hang
{
private:
    int KichThuoc;
    Date NgayNhap;
public:
    void Nhap()
    {
        Hang::Nhap();
        cout << "Nhap kich thuoc tivi :";
        cin >> KichThuoc;
        cout<<"Nhap ngay nhap "<<endl;
        NgayNhap.Nhap();
    }
    void Xuat()
    {
        Hang::Xuat();
        cout <<setw(11) <<KichThuoc;
        NgayNhap.Xuat();
    }
    Tivi()
    {
        Hang();
        KichThuoc = 25;
        NgayNhap.D= 19;
        NgayNhap.M= 11;
        NgayNhap.Y= 2020;
    }
};
void Hien()
{
    cout<<setw(15)<<"Ten hang";
    cout << setw(15) <<"Ten NSX";
    cout<<setw(15)<<"Dia Chi";
    cout << setw(10)<<"Gia";
    cout <<setw(11)<<"Kichthuoc";
    cout << setw(11) << "Ngay Nhap"<<endl;
}
int main()
{
    Tivi h;
    h.Nhap();
    cout << "\t\t\t ---Thong tin Tivi---"<<endl;
    Hien();
    h.Xuat();
    system("pause");
    system("cls");
    h=Tivi();
    cout << "\t\t\t ---Thong tin Tivi---"<<endl;
    Hien();
    h.Xuat();
    return 0;
}
