#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Item.hpp"
#include "FileHandler.hpp"
#include <string>

using namespace std;

class Weapon : public Item {
    private:
        double attackPower;
        string description;

    public:
        Weapon(string name, double weight, double attackPower, string description, string prefix, string suffix);
        Weapon(Weapon *Weapon);
        Weapon(WeaponStruct weapon);

        string getName() const override;
        double getWeight() const override;

        double getAttackPower() const;

        string getPrefix() const override;
        string getSuffix() const override;

        string getDescription() const;

        string getType() const override;

        ~Weapon() override;
};

#endif