#include<iostream>
using namespace std;

int main() {
    double a;
    cout << "Enter value in degrees: ";
    cin >> a;
    
    double b = (a * 3.141593) / 180;
    cout << "Value in radians: "<< b << endl;
    return 0;
}