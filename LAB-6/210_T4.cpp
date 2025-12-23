#include<iostream>
using namespace std;

class TradeSignal{
private:
    double magnitude;
    long timestamp;
public:
    TradeSignal() : magnitude(0.0), timestamp(0) {}
    TradeSignal(int mag, int tim) : magnitude(mag), timestamp(tim) {}
    ~TradeSignal() {}

    double getMagnitude() const{ return magnitude; }
    long getTimestamp() const{ return timestamp; }

    void setMagnitude(int mag){
        if(mag < 0){
            cout << "Invalid" << endl;
            return;
        }
        magnitude = mag;
    }
    void setTimestamp(int tim){
        if(tim < 0){
            cout << "Invalid" << endl;
            return;
        }
        timestamp = tim;
    }
    TradeSignal operator+(TradeSignal &obj) const{
        double newMag = this->getMagnitude() + obj.getMagnitude();
        long newtime = this->getTimestamp() + obj.getTimestamp();

        return TradeSignal(newMag, newtime);
    }
    TradeSignal operator*(double scaler) const{
        return TradeSignal(this->getMagnitude() * scaler, this->getTimestamp());
    }
};

TradeSignal operator*(double scaler, TradeSignal &obj){
    double newMag = scaler * obj.getMagnitude();
    long time = obj.getTimestamp();

    return TradeSignal(newMag, time);
}
ostream& operator<<(ostream& os, const TradeSignal &obj) {
    os << "[" << obj.getTimestamp() << "]\nMagnitude: " << obj.getMagnitude() << endl; 
    return os;
}

int main(){
    TradeSignal s1(12.5, 2001);

    TradeSignal s2 = 2.5 * s1;

    cout << "Original: " << s1 << endl;
    cout << "Amplified: " << s2 << endl;
}