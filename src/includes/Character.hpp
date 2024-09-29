#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Item.hpp"

using namespace std;

class Character {
    protected:
        string name;
        double maxHealth;
        double currentHealth;

    public:
        Character(string name, double maxHealth);

        virtual void attack(Character *target) = 0;
        virtual string getDescription() const = 0;

        string getName() const;
        double getMaxHealth() const;
        double getCurrentHealth() const;
        void takeDamage(double damage);
        void heal(double amount);

        virtual ~Character() = 0;

        bool isAlive() const;
};

#endif
