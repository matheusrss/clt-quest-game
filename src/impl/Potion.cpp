#include "Potion.hpp"
#include "Character.cpp"
#include <string>

using namespace std;



Potion::Potion(string name, double weight, double healingPower, string description) {
    this-> name = name;
    this-> weight;
    this-> healingPower;
    this-> description = description;
}

string Potion::getName() const {
    return name;
}

double Potion::getWeight() const {
    return weight;
}

double Potion::getHealingPower() const {
    return healingPower;
}

/*void Potion::applyHealing(Character* character) {

}*/

Potion::~Potion() {

}