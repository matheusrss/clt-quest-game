#ifndef GAME_HPP
#define GAME_HPP

#include "Hero.hpp"
#include "MapInterface.hpp"
#include "map.hpp"
#include "FileHandler.hpp"


using namespace std;

class Game {
    private:
        MapInterface *currentMap;
        Hero *hero;

        int level;
        double score;
        bool mode;

        EnemyStruct* enemies;
        WeaponStruct* weapons;
        PotionStruct* potions;

    public:
        Game(Hero *hero, int mode);

        void changeMap(MapInterface *newMap);

        void start();

        void displayCurrentMap() const;

        void end();

        void increaseScore(double enemyAttack, double health);

        ~Game();
};

#endif
