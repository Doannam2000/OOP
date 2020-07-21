#include <iostream>

using namespace std;

class Arr{
    private:
        int a[100];
        int n;
    public:
        Arr operator++();
        Arr operator--();
        friend ostream &operator<<(ostream &out, Arr &arr);
        friend istream &operator>>(istream &in, Arr &arr);
};

istream &operator>>(istream &in, Arr &arr){
    cout << "Nhap so phan tu cua mang: ";    cin >> arr.n;

    for(int i = 0; i < arr.n; i++){
        cout << "a[" << i << "] = ";
        in >> arr.a[i];
    }
    return in;
}
ostream &operator<<(ostream &out, Arr &arr){
    cout << "Danh sach cac phan tu: " << endl;

    for(int i = 0; i < arr.n; i++){
        cout << "a[" << i << "] = ";
        out << arr.a[i];
        cout << "\t";
    }
    return out;
}

Arr Arr::operator++(){
    for(int i = 0; i < this->n; i++){
        for(int j = this->n - 1; j > i; j--){
              if(this->a[j] < this->a[j-1]){
                int tg = this->a[j];
                this->a[j] = this->a[j-1];
                this->a[j-1] = tg;
              }
        }
      }
      return *this;
}
Arr Arr::operator--(){
    for(int i = 0; i < this->n; i++){
        for(int j = this->n - 1; j > i; j--){
              if(this->a[j] > this->a[j-1]){
                int tg = this->a[j];
                this->a[j] = this->a[j-1];
                this->a[j-1] = tg;
              }
        }
      }
      return *this;
}

int main(){
    Arr a;
    cin >> a;
    ++a;
    cout<<"\nMang tang dan: ";
    cout << a;
    cout<<"\nMang giam dan: ";
    --a;
    cout<<a;
    return 0;
}
