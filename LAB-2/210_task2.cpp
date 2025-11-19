#include<iostream>
using namespace std;

enum type{
    laborer, secretary, manager, accountant, executive, researcher
};
int main(){
    char n;
    enum type etype;
    cin >> n;
    switch(n){
        case 'l':
            etype = laborer;
            break;
        case 's':
            etype = secretary;
            break;
        case 'm':
            etype = manager;
            break;
        case 'a':
            etype = accountant;
            break;
        case 'e':
            etype = executive;
            break;
        case 'r':
            etype = researcher;
            break;
        default:
            cout << "Invalid input\n";
            break;
    }
    switch(etype){
        case laborer:
            cout << "Laborer\n";
            break;
        case secretary:
            cout << "Secretary\n";
            break;
        case manager:
            cout << "Manager\n";
            break;
        case accountant:
            cout << "Accountant\n";
            break;
        case executive:
            cout << "Executive\n";
            break;
        case researcher:
            cout << "Researcher\n";
            break;
        default:
            cout << "Invalid input\n";
            break;
        

    }

}