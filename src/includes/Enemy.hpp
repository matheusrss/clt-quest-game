#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Character.hpp"
#include "FileHandler.hpp"

class Enemy : public Character {
    private:
        double attackPower;
        string description;

    public:
        Enemy(string name, double maxHealth, double attackPower, string description);
        Enemy(EnemyStruct enemy);

        void attack(Character *target) override;
        string getDescription() const override;

        double getAttackPower() const;

        ~Enemy() override;
};

#endif
