#include<iostream>
using namespace std;

class TaxEstimator{
private:
    double total_income;
    double total_expense;
    double determineBracketRate(){
        double temp = 0;
        double net_income = total_income - total_expense;
        if(net_income < 10000){
            return 0;
        }
        else if(net_income > 10000 && net_income < 50000){
            temp = .10;
            return temp;
        }else if(net_income > 50000){
            temp = .20;
            return temp;
        }
    }
public:
    TaxEstimator(){
        total_income = 0;
        total_expense = 0;
    }
    ~TaxEstimator(){
        cout << "Tax session closed";
    }
    void addIncomeSource(double amount){
        if(amount < 0){
            cout << "Negative income is bad for the economy and my code." << endl;
        }else total_income += amount;
    }
    void addExpense(double amount){
        total_expense += amount;
    }
    void printTaxSlip(){
        int net_income = total_income - total_expense;
        int total_tax = determineBracketRate() * net_income;
    }

};