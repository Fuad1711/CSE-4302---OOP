#include<iostream>
using namespace std;

class SmartElevator{
private:
    int cur_floor;
    double total_weight;
    int max_floor;
public:
    SmartElevator(int max_floor){
        cur_floor = 0;
        total_weight= 0.0;
    }
    ~SmartElevator(){
        cout << "Elevator system entering maintenance mode." << endl;
    }
    void boardPassenger(int weight){
        if(total_weight > 4302.00){
            cout << "Overload! Someone must exit." << endl;
        }else total_weight += weight;
    }
    void goToFloor(int target){
        if(target >= 0 && target <= max_floor){ 
            if(target == cur_floor){
                cout << "Staying put engaged. Enjoy the view!" << endl;
            }else cur_floor = target;
        }else cout << "Error 404: Floor not found. Try reality instead." << endl;
    }
    void displayPanel(){
        cout << "Current floor: " <<cur_floor << "\n" << "Current load: " << total_weight << endl;
    }   
};