#include<iostream>
#include<string.h>
#include<iomanip>
class FACULTY;
using namespace std;
class PERSON
{
protected:
    char Name[15];
    char Birth[12];
    char Address[15];
public:
    void Input()
    {
        cout<< "Nhap ten :";
        fflush(stdin);
        gets(Name);
        cout<< "Nhap ngay sinh (dd/mm/yyyy) :";
        fflush(stdin);
        gets(Birth);
        cout<< "Nhap dia chi :";
        fflush(stdin);
        gets(Address);
    }
    void output()
    {
        cout<< left << setw(15) <<Name;
        cout << setw(12) << Birth;
        cout << setw(15) << Address;
    }
    Person()
    {
        strcpy(Name,"Duy Nam");
        strcpy(Birth,"19/11/2000");
        strcpy(Address,"Hai Phong");
    }
};
class SCHOOL
{
private:
    char Name[15];
    char Date[15];
public:
    friend class FACULTY;
    friend class STUDEN;
};
class FACULTY
{
private:
    char Name[15];
    char Date[12];
    SCHOOL x;
public:
    friend class STUDEN;
    void input()
    {
        cout<<"Nhap ten truong :";
        fflush(stdin);
        gets(x.Name);
        cout<<"Nhap nam thanh lap cua truong :";
        fflush(stdin);
        gets(x.Date);
        cout<<"Nhap ten giang vien :";
        fflush(stdin);
        gets(Name);
        cout<<"Nhap ngay sinh (dd/mm/yyyy):";
        fflush(stdin);
        gets(Date);
    }
    void output()
    {
        cout<< left<< setw(15) << Name ;
        cout << setw(12) << Date ;
        cout << setw(15) << x.Name;
        cout << setw(12) << x.Date;
    }
};
class STUDEN : public PERSON
{
private:
    FACULTY y;
    char Class[10];
    float Score;
public:
    void input()
    {
        PERSON::Input();
        y.input();
        cout<<"Nhap lop :";
        fflush(stdin);
        gets(Class);
        cout<<"Nhap diem :";
        cin>>Score;
    }
    void output()
    {
        PERSON::output();
        y.output();
        cout << left << setw(10)<<Class;
        cout << setw(5) << Score << endl;
    }
    Studen()
    {
        Person();
        strcpy(y.Name,"Cam Ngoan");
        strcpy(y.Date,"01/01/1990");
        strcpy(y.x.Name,"HaUI");
        strcpy(y.x.Date,"01/01/1970");
        strcpy(Class,"CNTT3");
        Score = 10;
    }
};
Hien()
{
    cout << left << setw(15) <<"Ten SV";
    cout << setw(12) <<"Ngay Sinh";
    cout << setw(15) <<"Dia Chi";
    cout << setw(15) <<"Ten GV";
    cout << setw(12) <<"Ngay Sinh";
    cout << setw(15) <<"Ten Truong";
    cout << setw(12) <<"Ngay TL";
    cout << setw(10) <<"Lop";
    cout << setw(5) <<"Diem"<<endl;
}
int main()
{
    STUDEN a;
    a.input();
    Hien();
    a.output();
    system("pause");
    return 0;
}
