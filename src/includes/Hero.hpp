#ifndef HERO_HPP
#define HERO_HPP

#include "Character.hpp"
#include "Backpack.hpp"
#include "Belt.hpp"

class Hero : public Character {
    private:
        Backpack backpack;  
        Belt belt;         

    public:
        Hero(string name, double maxHealth, double maxWeightPerSlot);

        void attack(Character* target) override;
        string getDescription() const override;

        void addItemToBackpack(Item* item);
        void addItemToBelt(Item* item, int slot);
        Item* getItemFromBackpack() const;
        Item* getItemFromBelt(int slot) const;

        ~Hero() override;
};

#endif 
