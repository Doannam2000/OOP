#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
class PhuongTrinhB2
{
private:
	float a, b, c;
public:
	void Nhap();
	void Xuat();
	void Nghiem();
	PhuongTrinhB2()
	{
		a = b = c = 0;
	}
	PhuongTrinhB2(float x, float y, float z)
	{
		a = x; b = y; c = z;
	}
};
typedef class PhuongTrinhB2 Bc2;
void Bc2::Nhap() {
	cout << "\nNhap a: "; 
	cin >> a;
	cout << "\nNhap b: "; 
	cin >> b;
	cout << "\nNhap c: "; 
	cin >> c;
}
void Bc2::Xuat() 
{
	cout << "\nPT: " << a << "*x^2 + " << b << "*x";
	if (c >= 0)
		cout << " + ";
	cout << c << " = 0" << endl;
}
void Bc2::Nghiem() 
{
	if (a == 0) 
	{
		if (b == 0) 
		{
			if (c == 0) 
			{
				cout << "\n Phuong trinh co vo so nghiem" << endl;
			}
			else cout << "\n Phuong trinh vo nghiem" << endl;
		}
		else cout << "\n Phuong trinh co nghiem duy nhat: " << -c / b;
	}
	else {
		float delta = b * b - 4 * a * c;
		if (delta < 0) 
		{
			cout << "\n Phuong trinh vo nghiem" << endl;
		}
		else if (delta == 0) 
		{
			float x = -b / (2 * a);
			cout << "\n Phuong trinh co nghiem kep x1 = x2 = " << setprecision(3) << x << endl;
		}
		else 
		{
			float x1 = (-b + sqrt(delta)) / 2 / a;
			float x2 = (-b - sqrt(delta)) / 2 / a;
			cout << "\n Phuong trinh co 2 nghiem phan biet: " << endl;
			cout << "\t\t x1 = " << setprecision(3) << x1 << "\t x2 =  " << setprecision(3) << x2;
		}
	}
}
int main() {
	Bc2 P;
	P = Bc2(2, 3, 1);
	P.Xuat();
	P.Nghiem();
	Bc2 Q;
	cout << "\n\t\tNhap phuong trinh Q" << endl;
	Q.Nhap();
	Q.Xuat();
	Q.Nghiem();
	return 0;
}