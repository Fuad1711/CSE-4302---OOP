#include<iostream>
using namespace std;

class BatchMeter{
private:
    int total = 0;
    int pulseSize = 1;
public:
    void setPulseSize(int s){
        if(s > 0) pulseSize = s;
        else cout << "Invalid pulse; must be > 0" << endl;
    }
    int getTotal(){
        return total;
    }
    void addpulse(){
        total += pulseSize;
    }
    void getClear(){
        total = 0;
    }
};

int main() {
    
}