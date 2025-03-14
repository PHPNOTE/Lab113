#include <iostream>
using namespace std;

class Transportation{
public:
    virtual double fare() = 0;
};

//------Class Taxi--------
class Taxi : public Transportation{
    private:
        double distance;
    public:
        void setDistance(double ds){
            distance = ds;
        }
    
        double fare() override{
            return (distance*2) + 35;
        }
};
//------Class BmtaBus-------
class BmtaBus :  public Transportation{
    public:
        double fare() override{
            return 6.50;
        }
};
//------Class BTS----------
class BTS : public Transportation{
    private:
        int numStation;
    public:
        void setStation(int st){
            numStation = st;
        }
        double fare() override{
            return 15 + (numStation * 5);
        }
    };
//------Class Passenger-----
class Passenger{
private:
    double totalFare = 0;
public:
    void addTransportation(Transportation &tp){
        totalFare += tp.fare();
    }
    double getTotalFare(){
        return totalFare;
    }
};

int main()
{
    Passenger passenger;
    while(1) {
        char transportType;
        cin >> transportType;
        if (transportType == 'A') {
            Taxi *taxi = new Taxi();
            double distance;
            cin >> distance;
            taxi->setDistance(distance);
            passenger.addTransportation(*taxi);
        } else if (transportType == 'B') {
            BmtaBus *bus = new BmtaBus();
            passenger.addTransportation(*bus);
        } else if (transportType == 'C') {
            BTS *bts = new BTS();
            int station;
            cin >> station;
            bts->setStation(station);
            passenger.addTransportation(*bts);
        } else {
            break;
        }
    }
    cout << "Total Fare: " << passenger.getTotalFare() << endl;
}