#include <iostream>
#include <vector>
using namespace std;

class Material {
private:
    string name;
    int quality;
    vector<string> compatibleTypes;

public:
    Material(string name, int quality);
    string getName();
    int getQuality();
    void addCompatibleType(string type);
    bool isCompatibleWith(string weaponType);
    int getUpgradeValue();
};

Material::Material(string nameIn, int qualityIn){
    this->name = nameIn;
    if(qualityIn > 5){
        qualityIn = 5;
    }
    if(qualityIn < 1){
        qualityIn = 1;
    }
    quality = qualityIn;
}

string Material::getName(){
    return name;
}

int Material::getQuality(){
    return quality;
}

void Material::addCompatibleType(string newType){
    compatibleTypes.push_back(newType);
}

bool Material::isCompatibleWith(string cmp){
    for(int i = 0; i < compatibleTypes.size(); i++){
        if(compatibleTypes[i] == cmp){
            return true;
        }
    }
    return false;
}

int Material::getUpgradeValue(){
    return quality*5;
}