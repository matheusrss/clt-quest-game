#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Character.hpp"

class Enemy : public Character {
    private:
        double attackPower;
        string description;

    public:
        Enemy(string name, double maxHealth, double attackPower, string description);

        void attack(Character* target) override;
        string getDescription() const override;

        double getAttackPower() const;

        ~Enemy() override;
};

#endif 
