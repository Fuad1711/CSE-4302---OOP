#include<iostream>
using namespace std;

class DigitalWallet{
private:
    int userID;
    double balance;
    bool checkBalance(){
        if(balance < 0) return true;
    }
public:
    DigitalWallet() : userID(0), balance(0) {}
    DigitalWallet(int id, double bal) : userID(id), balance(bal) {
        if(balance < 0){
            cout << "Error zero balance." << endl;
        }
    }

    int getuserID() const{ return userID;}
    int getbalance() const{ return balance;}
    void setID(int id){
        userID = id;
    }
    void setbalance(double bal){
        balance = bal;
    }
    DigitalWallet(int id, int bal){
        userID = id;
        balance = bal;
    }
    DigitalWallet operator+(double amount) const{
        return DigitalWallet(userID, balance + amount);
    }
    DigitalWallet operator-(double amount){
        DigitalWallet result = DigitalWallet(userID, balance - amount);
        if(checkBalance()){
            cout << "Error: Balance negative" << endl;
        }
        return result;
    }
    DigitalWallet operator*(double interest){
        return DigitalWallet(userID, balance * interest);
    }
    operator long() const{
        return balance * 100;
    }

    void checkstatus(){
        cout << "ID: " << userID << endl;
        cout << "Balance: " << balance << endl;

    }
};

int main(){
    DigitalWallet w1(10, 100);
    DigitalWallet w2(21, 200);
    w2 =  w1 + 100;
    // w1.operator*(100);
    w2.checkstatus();
    
}