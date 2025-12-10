#include<iostream>
using namespace std;

class Zombie{
private:
    int health;
    static int total;
public:
    Zombie(int zom_health){
        health = zom_health;
        total++;
        cout << "A new zombie rises! Total count: " << total << endl;
    }
    ~Zombie(){
        total--;
        cout << "Zombie eliminated. Total remaining: " << total << endl;
    }

    void takedamage(int damage){
        if(health <= 0) cout << "Zombie is down" << endl;
        health -= damage;
    }
    int getHordeCount() const{
        return total;
    }
};

int Zombie :: total = 0;