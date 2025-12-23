#include<iostream>
#include<math.h>
using namespace std;


class Hero{
private:
    string heroName;
    string classType;
    int attackPower;
    int defensePower;
public:
    Hero(): heroName("Unknown"), classType("Novice"), attackPower(10), defensePower(10){}
    Hero(string name, string type, int atk, int def):  heroName(name), classType(type), attackPower(atk), defensePower(def) {}

    string getheroName() const { return heroName;}
    string getclasstype() const { return classType;}
    int getpower() const { return attackPower;}
    int getdef() const { return defensePower;}

    void setheroname(string name){
        heroName = name;
    }
    void setclasstype(string type){
        classType = type;
    }
    void setattack(int atk){
        attackPower = atk;
    }
    void setdefense(int def){
        defensePower = def;
    }
    Hero spar(Hero opponent, Hero user){
        double mypower = pow(attackPower, 0.7) + attackPower / (attackPower + opponent.defensePower);
        double opp = pow(defensePower, 0.6) + defensePower / (defensePower + opponent.attackPower);
        if(mypower >=  opp){
            return user;
        }else return opponent;
    }

    void display(){
        cout << "Hero name: " << heroName << endl;
        cout << "Hero class: " << classType << endl;
        cout << "Attack: " << attackPower << endl;
        cout << "defense: " << defensePower << endl;
    }

};
int main(){

    Hero heroes[5] = {
        Hero("Aurin", "Warrior", 80, 70),
        Hero("Abir", "Mage", 95, 40),
        Hero("Abrar", "Tank", 75, 85),
        Hero("Hassan", "Healer", 90, 50),
        Hero("Fyz", "HogRider", 85, 65)
    };
    Hero winner = heroes[0];
    for(int i = 1; i < 5; ++i){
        winner = winner.spar(heroes[i], winner);
    }

    winner.display();
}