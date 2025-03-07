#include <iostream>
#include <vector>
using namespace std;


//------------------------ Class Material -------------------------------------------
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

//------------------------ Class Weapon -------------------------------------------

class Weapon {
    private:
        int durability;
        int damage;
        string weaponType;
    
    public:
        Weapon(int durability, int damage, string weaponType);
        int getDurability();
        int getDamage();
        string getWeaponType();
        int attack();
        bool upgrade(Material material);
        void repair();
        void showStatus();
};

int Weapon::getDamage(){
    return damage;
}
int Weapon::getDurability(){
    return durability;
}
string Weapon::getWeaponType(){
    return weaponType;
}

Weapon::Weapon(int durability, int damage, string weaponType){
    if(durability < 0){
        durability = 0;
    }
    if(durability > 100){
        durability = 100;
    }
    if(damage < 0){
        damage = 0;
    }
    this->weaponType = weaponType;
    this->damage = damage;
    this->durability = durability;
}

int Weapon::attack(){
    if(durability == 0){
        return 0;
    }else{
        if(durability < 2){
            durability = 0;
        }else{
            durability -= 2;
        }
        return damage;
    }
}

bool Weapon::upgrade(Material mtr){
    if(mtr.isCompatibleWith(this->weaponType)){
        this->damage += mtr.getUpgradeValue();
        return true;
    }
    return false;
}

void Weapon::repair(){
    this->durability = 100;
}

void Weapon::showStatus(){
    cout << durability << " " << damage << " " << weaponType << endl;
}


//------------------------ Class Sword -------------------------------------------

class Sword : public Weapon {
    private:
        double criticalMultiplier;
    
    public:
        Sword(int durability, int damage, double criticalMultiplier);
        double getCriticalMultiplier();
        void setCriticalMultiplier(double multiplier);
        int attack();
        void showStatus();
};

double Sword::getCriticalMultiplier(){
    return criticalMultiplier;
}

void Sword::setCriticalMultiplier(double multiplier){
    if(multiplier < 1.0){
        multiplier = 1.0;
    }
    this->criticalMultiplier = multiplier;
}

Sword::Sword(int durability, int damage, double criticalMultiplier):Weapon(durability,damage,"Sword"){
    if(criticalMultiplier < 1.0){
        criticalMultiplier = 1.0;
    }
    this->criticalMultiplier = criticalMultiplier;
}

int Sword::attack() {
    if(this->getDurability() == 0){
        return 0;
    }
    int base = Weapon::attack();
    return base*criticalMultiplier;
}

void Sword::showStatus()  {
    cout << this->getDurability() << " " 
    << this->getDamage() << " " 
    << this->getWeaponType() << " " 
    << criticalMultiplier;
}