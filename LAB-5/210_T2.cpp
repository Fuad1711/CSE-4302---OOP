#include<iostream>
using namespace std;

class gymprofile{
private:
    string memberName;
    string membershipTier;
    double bodyWeight;
    double benchPressMax;
public:
   gymprofile() : memberName("N/A"), membershipTier("N/A"), bodyWeight(0), benchPressMax(0){}
   gymprofile(string name, string tier, double weight, double max) : memberName(name), membershipTier(tier), bodyWeight(weight), benchPressMax(max){}
   string getname(){
    return memberName;
   }
   string gettier(){
    return membershipTier;
   }
   double getweight(){
    return bodyWeight;
   }
   double getmax(){
    return benchPressMax;
   }
   void setname(string n){
    memberName = n;
   }
   void settier(string tier){
    if(tier.length() > 3){
        membershipTier = tier;
    }else membershipTier = "Standard";
   }
   void setweight(double w){
    if(w > 40 && w < 200){
        bodyWeight = w;
    }else bodyWeight = 70;
   }
   void setmax(double m){
    benchPressMax = m;
   }
   void display(){
    cout << "";
   }
};
int main(){

}