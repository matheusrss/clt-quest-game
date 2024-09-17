#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Item.hpp"
#include <string>

using namespace std;


class Weapon : public Item {
    private:
        double attackPower;

    public:
        Weapon(string name, double weight, double attackPower);

        void initialize(string name, double weight) override;

        string getName() const override;
        double getWeight() const override;

        double getAttackPower() const;

        ~Weapon() override;
};


#endif