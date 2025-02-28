#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

//accidently use to_string in n05 and somehow it is also the answer for n06 (I just use all my luck)

class Time {
private:
    int hour;
    int minute;
    int second;
public:
    Time(int hour, int minute, int second){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    Time(int duration){
        hour = duration/3600;
        duration%=3600;
        minute = duration/60;
        duration%=60;
        second = duration;
    }
    int getDuration(){
        return second + (minute*60) + (hour*3600);
    }
    Time add(Time other){
        int sumTime = (this->getDuration()) + other.getDuration();
        if(sumTime >= 86400){
            sumTime %= 86400;
        }
        Time result(sumTime);
        return result;
    }
    int subtract(Time other){
        int time1 = this->getDuration();
        int time2 = other.getDuration();
        int timediff = abs(time1-time2);
        if (time1 >= time2){
            return timediff;
        }else{
            return 86400 - timediff;
        }
    }
    int equals(Time other){
        if(this->getDuration() == other.getDuration()){
            return 1;
        }
        return 0;
    }
    string toString(){
        string h = (hour < 10) ? "0" + to_string(hour) : to_string(hour);
        string m = (minute < 10) ? "0" + to_string(minute) : to_string(minute);
        string s = (second < 10) ? "0" + to_string(second) : to_string(second);
        return h + ":" + m + ":" + s;
    }

    //getter and setter
    int getHour(){
        return hour;
    }
    int getMinute(){
        return minute;
    }
    int getSecond(){
        return second;
    }
    void setHour(int h) {
        this->hour = h;
    }
    void setMinute(int m) {
        this->minute = m;
    }
    void setSecond(int s) {
        this->second = s;
    }
}; 


int main() {
    Time t1(0);  
    Time t2(1,1,1);     
    cout << t1.toString()  << endl;  
    
    return 0;
}