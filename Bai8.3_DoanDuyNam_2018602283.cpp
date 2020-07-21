#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class TaiSan
{
private:
    char TenTS[20];
    int SL;
    char TinhTrang[25];
public:
    void Nhap()
    {
        cout<<"Nhap ten tai san :";
        fflush(stdin);
        gets(TenTS);
        cout << " Nhap so luong :";
        cin>>SL;
        cout << "Nhap tinh trang :";
        fflush(stdin);
        gets(TinhTrang);
    }
    void Xuat()
    {
        cout << setw(20) <<TenTS;
        cout << setw(10) << SL;
        cout << setw(25) <<TinhTrang <<endl;
    }
    friend int TongSL(TaiSan a[],int SLH);
};
class NhanVien
{
private:
    char NV[15];
    char CV[15];
public:
    void Nhap()
    {
        cout << "Nhap ten nhan vien kiem ke :";
        fflush(stdin);
        gets(NV);
        cout << "Nhap chu vu :";
        fflush(stdin);
        gets(CV);
    }
    void Xuat()
    {
        cout << left << setw(20) << "Nhan vien kiem ke:"<< setw(20) << NV;
        cout << setw(15) << "Chuc vu :"<< setw(15) << CV << endl ;
    }
    friend class Phieu;
};
class Phong
{
private:
    char TenPhong[25];
    char MaPhong[15];
    char TruongPhong[20];
public:
    void Nhap()
    {
        cout<<"Nhap thong tin phong kiem ke" <<endl;
        cout << "Nhap ten phong :";
        fflush(stdin);
        gets(TenPhong);
        cout << "Nhap ma phong :";
        fflush(stdin);
        gets(MaPhong);
        cout << "Nhap ten truong phong :";
        fflush(stdin);
        gets(TruongPhong);
    }
    void Xuat()
    {
        cout << setw(20) << "Kiem ke tai phong:"<<setw(20) << TenPhong;
        cout << setw(15) <<"Ma phong:" <<setw(15)<<MaPhong<<endl;
        cout << setw(20) <<"Truong phong :"<<TruongPhong<<endl;
    }
    friend class Phieu;
};
class Phieu
{
private:
    char MaPhieu[10];
    char Date[12];
    NhanVien x;
    Phong y;
    TaiSan a[100];
    int SLTS;
public:
    void Nhap()
    {
        cout <<" Nhap ma phieu :";
        fflush(stdin);
        gets(MaPhieu);
        cout<<"Nhap ngay kiem ke (dd/mm/yyyy):";
        fflush(stdin);
        gets(Date);
        x.Nhap();
        y.Nhap();
        cout << "Nhap so luong tai san :";
        cin >>SLTS;
        for(int i = 0; i < SLTS; i++)
        {
            cout <<" Nhap tai san "<< i + 1 <<endl;
            a[i].Nhap();
        }
    }
    void Xuat()
    {
        cout <<left <<setw(20) <<"Ma Phieu:" << setw(15) << MaPhieu;
        cout << setw(15) <<"Ngay kiem ke:" << setw(15) << Date << endl;
        x.Xuat();
        y.Xuat();
        cout << setw(20) <<"Ten tai san";
        cout << setw(10) << "So luong";
        cout << setw(25) << "Tinh trang"<<endl;
        for(int i = 0; i<SLTS ; i++)
        {
            a[i].Xuat();
        }
        cout <<left <<setw(30) << "So tai san da kiem ke : " <<setw(4)<<SLTS;
        cout << setw(10) <<"Tong SL :"<<setw(10) <<TongSL(a,SLTS)<<endl;
    }
    friend int TongSL(TaiSan a[],int SLTS);
};
int TongSL(TaiSan a[],int SLTS)
{
    int T;
    for(int i = 0; i<SLTS ; i++)
    {
        T += a[i].SL;
    }
    return T;
}
int main()
{
    Phieu h;
    cout << "\t ---Nhap thong tin phieu nhap hang---"<<endl;
    h.Nhap();
    cout << "\t ---Phieu Nhap Hang---"<<endl;
    h.Xuat();
    system("pause");
    return 0;
}
