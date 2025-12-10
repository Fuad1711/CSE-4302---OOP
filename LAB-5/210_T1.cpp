#include<iostream>
#include<string>
using namespace std;

class Pizza{
private:
    string pizzaname;
    string crusttype;
    int spicinessLevel;
    bool isExtraCheesy;
public:
    Pizza() : pizzaname("Unnamed"), crusttype("Unnamed"), spicinessLevel(0), isExtraCheesy(false){}
    Pizza(string pname, string ctype, int spice, bool xcheez) : pizzaname(pname), crusttype(ctype), spicinessLevel(spice), isExtraCheesy(xcheez){}
    string getPizzaName(){
        return pizzaname;
    }
    string getCrusttype(){
        return crusttype;
    }
    int getspice(){
        return spicinessLevel;
    }
    bool extra(){
        return isExtraCheesy;
    }
    void setPizzaName(string n){
        pizzaname = n;
    }
    void setPizzaspice(int level){
        if(level >= 1 && level <= 10){
            spicinessLevel = level;
        }else{
            spicinessLevel = 5;
        }
    }
    void setPizzacrust(string type){
        if(type == "Thin" || type == "Thick" || type == "Stuffed") crusttype = type;
        else type = "Thin";
    }
    void setisExtraCheesy(bool p){
        isExtraCheesy = p;
    }
    void display() const{
        cout << "Name: \n" << pizzaname;
        cout << "Crust: \n" << crusttype;
        cout << "Spiciness: \n" << spicinessLevel;
        cout << "Extra Cheesy: \n" << (isExtraCheesy ? "Yes" : "No");
    }
};
void prepareOrders(Pizza menu[], int size){
    string name, crust;
    int level;
    bool p;
    for(int i = 0; i < 4; ++i){
        cout << "Select the type of pizza: \n";
        getline(cin, name);
        cout << "Select crust type: \n";
        getline(cin, crust);
        cout << "Select spice level\n";
        cin >> level;
        cout << "Will it be Extra Cheesy? \n";
        cin >> p;
        menu[i] = Pizza(name, crust, level, p);
    }
    for(int i = 4; i < size; ++i){
        string name, crust;
        int level;
        bool a = (i % 2) == 0;
        menu[i].setPizzaName("Mystery Pizza");
        menu[i].setPizzacrust("Thin");
        menu[i].setPizzaspice((rand() % 10) + 1);
        menu[i].setisExtraCheesy(a);
    }
}

int main(){
    Pizza menu[30];
    prepareOrders(menu, 30);
    for (int i = 0; i < 30; i++) {
        if (menu[i].getspice() >= 7)
            menu[i].display();
    }
}