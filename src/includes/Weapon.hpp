#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Item.hpp"
#include <string>

using namespace std;


class Weapon : public Item {
    private:
        double attackPower;
        string description;

    public:
        Weapon(string name, double weight, double attackPower, string description);

        string getName() const override;
        double getWeight() const override;

        double getAttackPower() const;

        ~Weapon() override;
};


#endif