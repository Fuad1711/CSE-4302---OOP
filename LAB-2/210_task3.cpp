#include<iostream>
using namespace std;

struct fraction{
    int num;
    int den;
};

int main(){
    fraction f1, f2, sum;
    char dummychar = '/';
    cout << "Enter first fraction: ";
    cin >> f1.num >> dummychar >> f1.den;
    cout << "Enter second fraction: ";
    cin >> f2.num >> dummychar >> f2.den;
    sum.num = f1.num * f2.den + f2.num * f1.den;
    sum.den = f1.den * f2.den;
    cout << "Sum = " << sum.num << dummychar << sum.den << endl;
}