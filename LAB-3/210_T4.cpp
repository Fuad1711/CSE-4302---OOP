#include<iostream>
using namespace std;

class BatteryMonitor{
private:
    double percent = 100;
    double threshold = 15;
public:
    void setCriticalThreshold(double Percent){
        if(Percent >= 5.0 && Percent <= 25.0) threshold = Percent;
        else cout << "Invalid threshold; must be 5-25%" << endl;
    }
    void drain(double amount){
        if(amount < 0) cout << "Invalid drain amount" << endl;
        percent -= amount;
        if(percent < 0){
            percent = 0;
            cout << "Battery depleted" << endl;
        }
    }
    void recharge(double amount){
        percent += amount;
        if(amount < 0) cout << "Invalid recharge amount" << endl;
        if(percent > 100){
            percent = 100;
            cout << "Battery fully charged" << endl;
        }
    }
    bool needscharging(){
        if(percent <= threshold) return true;
    }
    void status(){
        cout << "Battery: " << percent << "%" << " ";
        if(needscharging()){
            cout << "[OK]" << endl;
        }else cout << "[CRITICAL]" << endl;
    }

};