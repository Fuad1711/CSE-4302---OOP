#include<iostream>
using namespace std;

class SnackProfile{
private:
    string name;
    string maker;
    double mrp = 0.0;
    double discount = 7;

public:
    void setLabels(const string itemName, const string itemMaker){
        name = itemName;
        maker = itemMaker;
    }
    void setMRP(double price){
        if(price > 0) mrp = price;
        else{
            mrp = 0.0;
            cout << "Invalid MRP; set to 0.0" << endl;
        }
    }
    void setDiscount(double percent){
        if(percent >= 0 && percent <= 25) discount = percent;
    }
    double getUnitPrice(){
        int selPrice = mrp * (1.0 - discount / 100.0);
        return selPrice;
    }
    double getTotalPrice(int qty = 1){
        if(qty < 0){
            cout << "Invalid quantity" << endl;
            return 0.0;
        }else return qty * getUnitPrice();
    }
    void info(){
        cout << name << " by " << maker << ": MRP " << mrp << ", Discount" << discount << "%, Unit" << getUnitPrice();
    }
};

int main(){

}