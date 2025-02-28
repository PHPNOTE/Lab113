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
    Hero Diddy("baby oil", 10);
    cout << Diddy.getLevel() << endl
        <<Diddy.getName();
}