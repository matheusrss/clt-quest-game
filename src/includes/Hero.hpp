#ifndef HERO_HPP
#define HERO_HPP

#include "Backpack.hpp"
#include "Belt.hpp"
#include "Character.hpp"
#include "Potion.hpp"
#include "Weapon.hpp"

class Hero : public Character {
    private:
        Backpack backpack;
        Belt belt;
        int baseDamage;
        Weapon *currentWeapon;

    public:
        Hero(string name, double maxHealth, double maxWeightPerSlot);

        void attack(Character *target) override;
        string getDescription() const override;

        void addItemToBackpack(Item *item);
        void addItemToBelt(Item *item, int slot);
        Item *getItemFromBackpack() const;
        Item *getItemFromBelt(int slot) const;

        Item *removeItemFromBackpack();

        Weapon *getWeapon() const;

        void equipWeapon(Weapon *weapon);

        int getBaseDamage() const;

        Item *removeItemFromBelt(int slot);

        void increaseBaseDamage(double percentage);
        void increaseHealth(double percentage);
        void healFullLife();


        ~Hero() override;
};

#endif
