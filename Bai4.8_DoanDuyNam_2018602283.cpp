#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class NhanVien;
class Date
{
private:
    int day,month,year;
public:
    friend class NhanVien;
};
class PhongBan
{
private:
    int maPb;
    char tenPb[50];
    char truongPhong[10];
    int soNv;
public:
    friend class NhanVien;
    friend void TaiChinh(NhanVien a[],int n);
};
class NhanVien
{
private:
    int maNv;
    char hoDem[25];
    char ten[10];
    Date ngaySinh;
    PhongBan phong;
public:
    void Nhap();
    void Xuat();
    friend void TaiChinh(NhanVien a[],int n);
    friend void SX(NhanVien a[],int n);
    friend void Chen(NhanVien a[],int &n);
    friend void Xoa(NhanVien a[],int &n);
};
void NhanVien::Nhap()
{
    cout<<"\nNhap ma nv: ";
    cin>>maNv;
    cout<<"Nhap ho dem: ";
    fflush(stdin);
    gets(hoDem);
    cout<<"Nhap ten: ";
    fflush(stdin);
    gets(ten);
    cout<<"Nhap ngay sinh: \n";
    cout<<"Nhap ngay: ";
    cin>>ngaySinh.day;
    cout<<"Nhap thang: ";
    cin>>ngaySinh.month;
    cout<<"Nhap nam: ";
    cin>>ngaySinh.year;
    cout<<"Nhap thong tin phong ban: \n";
    cout<<"Nhap ma phong ban: ";
    cin>>phong.maPb;
    cout<<"Nhap ten pb: ";
    fflush(stdin);
    gets(phong.tenPb);
    cout<<"Nhap ten truong phong: ";
    fflush(stdin);
    gets(phong.truongPhong);
    cout<<"Nhap so nhan vien: ";
    cin>>phong.soNv;
}
void NhanVien::Xuat()
{
    cout<<setw(8)<<maNv;
    cout<<setw(10)<<hoDem;
    cout<<setw(6)<<ten;
    cout<<setw(3)<<ngaySinh.day<<"/";
    cout<<setw(2)<<ngaySinh.month<<"/";
    cout<<setw(4)<<ngaySinh.year;
    cout<<setw(8)<<phong.maPb;
    cout<<setw(8)<<phong.tenPb;
    cout<<setw(12)<<phong.truongPhong;
    cout<<setw(5)<<phong.soNv<<endl;
}
void Hien()
{
    cout<<setw(4)<<"STT";
    cout<<setw(8)<<"Ma Nv";
    cout<<setw(10)<<"Ho Dem";
    cout<<setw(6)<<"Ten";
    cout<<setw(11)<<"Ngay Sinh";
    cout<<setw(8)<<"Ma Pb";
    cout<<setw(8)<<"Ten Pb";
    cout<<setw(12)<<"TruongPhong";
    cout<<setw(5)<<"Nv"<<endl;
}
void TaiChinh(NhanVien a[],int n)
{
    int d=0;
    cout << "------------ Danh sach nhan vien tai chinh ------------"<<endl;
    Hien();
    for (int i = 0; i < n; i++)
    {
        if (stricmp(a[i].ten,"Tai Chinh")== 0)
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
void SX(NhanVien a[],int n)
{
    for( int i=0 ; i<n-1 ; i++)
    {
        for(int j = i+1 ; j<n; j++)
        {
            if(stricmp(a[i].ten,a[j].ten)>0)
            {
                NhanVien x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }
    cout << "------------ Danh sach nv sau khi sap xep ------------"<<endl;
    Hien();
    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << i + 1;
        a[i].Xuat();
        cout << endl;
    }
}
void Chen(NhanVien a[],int &n)
{
    NhanVien x;
    cout << "Nhap Nhan vien can chen" <<endl;
    x.Nhap();
    int k;
    cout << "Nhap vi tri can chen :";
    cin >> k;
    /*	NhanVien *b = new NhanVien[n + 1];
    	for(int i = 0 ; i< n ; i++)
    	{
    		b[i]=a[i];
    	}
    	delete a;*/
    n++;
    a = (NhanVien*)realloc(a,n*sizeof(NhanVien));
    for(int i = 0 ; i<n - 1; i++)
    {
        if(i+1==k)
        {
            for(int j = n - 1; j>i; j--)
            {
                a[j] = a[j-1];
            }
            a[i] = x;
        }
    }
    /*a = new NhanVien[n];
    for(int i = 0 ; i< n ; i++)
    {
    	a[i]=b[i];
    }*/
    cout << "------------ Danh sach nv sau khi them ------------"<<endl;
    Hien();
    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << i + 1;
        a[i].Xuat();
        cout << endl;
    }
    //delete b;
}
void Xoa(NhanVien a[],int &n)
{
    for(int i = 0 ; i<n; i++)
    {
        if(a[i].maNv==123)
        {
            for(int j = i; j<n-1; j++)
            {
                a[j] = a[j+1];
            }
            n--;
            /*			NhanVien *b = new NhanVien[n];
            			for(int k = 0 ; k< n ; k++)
            			{
            				b[k]=a[k];
            			}
            			delete a;
            			a = new NhanVien[n];
            			for(int k = 0 ; k< n ; k++)
            			{
            				a[k]=b[k];
            			}
            			delete b;*/
            a = (NhanVien*)realloc(a,n*sizeof(NhanVien));
            i--;
        }
    }
    cout << "------------ Danh sach nv sau khi xoa ------------"<<endl;
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
    cout << "Nhap so luong nv:";
    cin >> n;
    NhanVien*a ;
    a = (NhanVien*)realloc(0,n*sizeof(NhanVien));
    //NhanVien* a = new NhanVien[n];
    cout << "------------ Nhap danh NV ------------"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap Nhan vien " << i + 1 ;
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
    TaiChinh(a,n);
    SX(a,n);
    Chen(a,n);
    Xoa(a,n);
    system("pause");
    free(a);
    return 0;
}
