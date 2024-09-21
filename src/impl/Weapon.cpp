#include "Item.hpp"
#include <string>
#include "Weapon.hpp"

using namespace std;

//cria o molde da arma 

Weapon::Weapon(string name,double weight,double attackPower, string description){
this-> name = name;
    this-> weight;
    this-> attackPower;
    this-> description = description;
}

//puxa o nome, peso e poder da arma

string Weapon::getName() const {
    return name;
}

double Weapon::getWeight() const {
    return weight;
}
double Weapon::getAttackPower() const {
    return attackPower;
}
Weapon::~Weapon() {

}