#include<iostream>
using namespace std;

class CreditCard{
private:
    double limit;
    double owed;
public:
    CreditCard(int lim){
        limit = lim;
        owed = 0;
    }
    ~CreditCard(){
        cout << "Card destroyed" << endl;
    }
    void makePurchase(double amount){
        if(owed > limit){
            cout << "Declined" << endl;
        }
        owed += amount;
    }
    bool compareAvailability(CreditCard card){
        double credit_obj = card.limit - card.owed;
        double credit = limit - owed;
        if(credit > credit_obj) return true;
        else return false;
    }
    void dislpayInfo() const{
        cout << "Limit: " << limit << endl;
        cout << "Current Balance: " << owed << endl;
        cout << "Available credit: " << limit - owed << endl;
    }
};

