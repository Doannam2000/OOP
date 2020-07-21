#include <iostream>

using namespace std;
class VECTO{
private:
    float X,Y,Z;
public:
    VECTO(float x, float y,float z)
    {
        this->X = x;
        this->Y = y;
        this->Z = z;
    }
    friend istream &operator>>(istream &is, VECTO &A);
    friend ostream &operator<<(ostream &os, VECTO A);
    VECTO operator+(VECTO A);
    VECTO operator-(VECTO A);
};
istream &operator>>(istream &is,VECTO &A)
{
    cout<<"\nNhap Toa Do X:";
    is>>A.X;
    cout<<"\nNhap Toa Do Y:";
    is>>A.Y;
    cout<<"\nNhap Toa Do Z:";
    is>>A.Z;
    return is;
}
ostream &operator<<(ostream &os, VECTO A)
{
    os<<"\t"<<"{"<<A.X<<","<<A.Y<<","<<A.Z<<"}"<<endl;
}
VECTO VECTO::operator+(VECTO A)
{
    VECTO tong = VECTO(0,0,0);
    tong.X  = X+ A.X;
    tong.Y = Y + A.Y;
    tong.Z = Z + A.Z;
    return tong;
}
VECTO VECTO::operator-(VECTO A)
{
    VECTO hieu = VECTO(0,0,0);
    hieu.X = X - A.X;
    hieu.Y = Y- A.Y;
    hieu.Z = Z - A.Z;
    return hieu;
}
int main()
{
    VECTO A = VECTO(0,0,0);
    VECTO B = VECTO(0,0,0);
    cout<<"\nNhap Toa Do VECVO Thu Nhat:";
    cin>>A;
    cout<<"\nNhap Toa Do VECTO Thu Hai:";
    cin>>B;
    VECTO hieu = A - B ;
	VECTO tong = A + B  ;
	cout<<"\n\tHieu 2 toa do:"<<hieu;
	cout<<"\n\tTong 2 toa do:"<<tong;
    return 0;
}
