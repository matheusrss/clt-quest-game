#include "Potion.hpp"
#include "Character.hpp"
#include "FileHandler.hpp"

#include <string>

using namespace std;

Potion::Potion(string name, double weight, double healingPower, string description, string prefix, string suffix) {
    this->name = name;
    this->weight;
    this->healingPower;
    this->description = description;
    this->prefix = prefix;
    this->suffix = suffix;
    this->type = "potion";
}

Potion::Potion(Potion* potion) {
    this->name = potion->name;
    this->weight = potion->weight;
    this->healingPower = potion->healingPower;
    this->description = potion->description;
    this->prefix = potion->prefix;
    this->suffix = potion->suffix;
}

Potion::Potion(PotionStruct potion) {
    this->name = potion.name;
    this->weight = potion.weight;
    this->healingPower = potion.healingPower;
    this->description = potion.description;
    this->prefix = potion.prefix;
    this->suffix = potion.suffix;
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

string Potion::getPrefix() const {
    return prefix;
}

string Potion::getSuffix() const {
    return suffix;
}

string Potion::getDescription() const {
    return description;
}

string Potion::getType() const {
    return type;
}


Potion::~Potion() {
}

