#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#define MAX_ENEMIES 100
#define MAX_POTIONS 100
#define MAX_WEAPONS 100

#include <string>

using namespace std;

// Struct para armazenar os dados de EnemyStruct
struct EnemyStruct {
    string name;
    double maxHealth;
    double attackPower;
    string description;
};

// Struct para armazenar os dados de PotionStruct
struct PotionStruct {
    string name;
    double weight;
    double healingPower;
    string description;
    string prefix;
    string suffix;
};

// Struct para armazenar os dados de WeaponStruct
struct WeaponStruct {
    string name;
    double weight;
    double attackPower;
    string description;
    string prefix;
    string suffix;
};

// Classe para manipular os dados de EnemyStruct
class EnemyHandler {
    public:
        int max = MAX_ENEMIES;
        int readEnemies(const char *filename, EnemyStruct *enemies);
        EnemyStruct *generateEnemiesArray(const char *filename, int &enemyCount);
};

// Classe para manipular os dados de PotionStruct
class PotionHandler {
        int max = MAX_POTIONS;

    public:
        int readPotions(const char *filename, PotionStruct *potions);
        PotionStruct *generatePotionsArray(const char *filename, int &potionCount);
};

// Classe para manipular os dados de WeaponStruct
class WeaponHandler {
        int max = MAX_WEAPONS;

    public:
        int readWeapons(const char *filename, WeaponStruct *weapons);
        WeaponStruct *generateWeaponsArray(const char *filename, int &weaponCount);
};

#endif
