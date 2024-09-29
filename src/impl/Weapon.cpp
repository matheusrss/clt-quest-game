#include "Weapon.hpp"
#include "Item.hpp"
#include "FileHandler.hpp"
#include <string>

using namespace std;

// cria o molde da arma

Weapon::Weapon(string name, double weight, double attackPower, string description, string prefix, string suffix) {
    this->name = name;
    this->weight = weight;
    this->attackPower = attackPower;
    this->description = description;
    this->prefix = prefix;
    this->suffix = suffix;
    this->type = "weapon";
}

Weapon::Weapon(Weapon *weapon) {
    this->name = weapon->getName();
    this->weight = weapon->getWeight();
    this->attackPower = weapon->getAttackPower();
    this->description = weapon->getDescription();
    this->prefix = weapon->getPrefix();
    this->suffix = weapon->getSuffix();
}

Weapon::Weapon(WeaponStruct weapon) {
    this->name = weapon.name;
    this->weight = weapon.weight;
    this->attackPower = weapon.attackPower;
    this->description = weapon.description;
    this->prefix = weapon.prefix;
    this->suffix = weapon.suffix;
}
   


// puxa o nome, peso e poder da arma

string Weapon::getName() const {
    return name;
}

double Weapon::getWeight() const {
    return weight;
}
double Weapon::getAttackPower() const {
    return attackPower;
}

string Weapon::getPrefix() const {
    return prefix;
}

string Weapon::getSuffix() const {
    return suffix;
}

string Weapon::getDescription() const {
    return description;
}

string Weapon::getType() const {
    return type;
}


Weapon::~Weapon() {
}

