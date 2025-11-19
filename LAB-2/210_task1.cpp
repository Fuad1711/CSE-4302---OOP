#include<iostream>
using namespace std;

int main(){
    int a, b, c, d;
    char dummychar = '/';
    cout << "Enter first fraction: ";
    cin >> a >> dummychar >> b;
    cout << "Enter second fraction: ";
    cin >> c >> dummychar >> d;
    int num = a * d + b * c;
    int den = b * d;
    cout << "Sum = " << num << dummychar << den << endl;
}