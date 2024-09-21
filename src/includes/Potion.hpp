#include <string>
#include "Item.hpp"
#include "Character.cpp"

using namespace std;


#ifndef POTION_H
#define POTION_H


class Potion : public Item {
    private:
        double healingPower;
        string description;

    public:
        Potion(string name, double weight, double healingPower, string description);

        string getName() const override;
        double getWeight() const override;

        double getHealingPower() const;

        void applyHealing(Character* character);

        ~Potion() override;
};


#endif