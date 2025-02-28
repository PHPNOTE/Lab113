#include <iostream>
#include <string>
using namespace std;

class Hero {
private:
    string name;
    int level;
public:
    Hero(string inname, int inlevel){
        name = inname;
        level = inlevel;
    }
    string getName(){
        return name;
    }
    int getLevel(){
        return level;
    }
};

int main(){
    string name;
    int input;
    cin >> name >> input;
    Hero num1(name, input);
    cout << num1.getName() + " " << num1.getLevel();
}