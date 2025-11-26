#include<iostream>
using namespace std;

class RatioQuota{
private:
    int num;
    int denom;
public:
    void setRatio(int p, int q){
        num = p;
        denom = q;
    }
    double asDecimal(){
        return (double)num / (double)denom ;
    }
    void reciprocal(){
        if(num != 0){
            int temp = num;
            num = denom;
            denom = temp;
        }else cout << "Reciprocal failed: zero cannot be a denominatior" << endl;
    }
    void show(){
        cout << "Ratio: " << asDecimal() << endl;
    }


};