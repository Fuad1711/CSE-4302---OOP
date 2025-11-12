#include<iostream>
using namespace std;

int main() {
    int n, geese;
    cout << "Enter initial geese count: ";
    cin >> n;
    if(n % 2 != 0){
        geese = (n * 13) / 2 + 1 + n;
    }else geese = (n * 13) /2 + n;
    cout << geese;
}