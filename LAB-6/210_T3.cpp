#include<iostream>
using namespace std;

class StopWatch{

private:
    int hours_;
    int minutes_;
    int seconds_;
    void rollover(){
        if(seconds_ >= 60){
            minutes_ += seconds_/60;
            seconds_ %= 60;
        }
        if(minutes_ >= 60){
            hours_ += minutes_/60;
            seconds_ %= 60;
        }
    }
public:
    StopWatch() : hours_(0), minutes_(0), seconds_(0) {}
    StopWatch(int hour, int minutes, int seconds) : hours_(hour), minutes_(minutes), seconds_(seconds) {}
    ~StopWatch(){}

    int gethour() const{ return hours_; }
    int getminutes() const{ return minutes_; }
    int getseconds() const{ return seconds_; }

    void sethour(int h){
        hours_ = h;
        rollover();
    }
    void setminutes(int m){
        minutes_ = m;
        rollover();
    }
    void setseconds(int s){
        seconds_ = s;
        rollover();
    }
    StopWatch &operator++(){
        seconds_++;
        rollover();
        return *this;
    }
    StopWatch operator++(int){
        StopWatch temp = *this;
        ++(*this);
        return temp;
    }
};

ostream& operator<<(ostream& os, const StopWatch &obj){
    os << obj.gethour() << ":" << obj.getminutes() << ":" << obj.getseconds() << endl;
    return os;
}
istream& operator>>(istream& is, StopWatch &obj){
    int h, m, s;
    if(is >> h >> m >> s){
        obj.sethour(h);
        obj.setminutes(m);
        obj.setseconds(s);
    }

    return is;
}


int main(){
    StopWatch s1;

    cout << "Enter time (HH/MM/SS): " << endl;
    cin >> s1;
    cout << "Initial time: " << s1 << endl;

    ++s1;
    cout << "After prefix ++: " << s1 << endl;

    StopWatch old = s1++;
    cout << s1 << endl;
    cout << old << endl;
}