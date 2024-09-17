#include <string>
#include "Item.hpp"

using namespace std;


#ifndef POTION_H
#define POTION_H


class Potion : public Item {
    private:
        double healingPower;

    public:
        Potion(string name, double weight, double healingPower);

        void initialize(string name, double weight) override;

        string getName() const override;
        double getWeight() const override;

        double getHealingPower() const;

        ~Potion() override;
};


#endif