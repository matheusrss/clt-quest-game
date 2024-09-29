#include <string>

#include "Item.hpp"
#include "FileHandler.hpp"

using namespace std;

#ifndef POTION_H
#define POTION_H

class Potion : public Item {
    private:
        double healingPower;
        string description;

    public:
        Potion(string name, double weight, double healingPower, string description, string prefix, string suffix);
        Potion(Potion* potion);
        Potion(PotionStruct potion);

        string getName() const override;
        double getWeight() const override;

        double getHealingPower() const;

        string getPrefix() const override;
        string getSuffix() const override;
        string getType() const override;

        string getDescription() const;


        ~Potion() override;
};

#endif