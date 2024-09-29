#include "FileHandler.hpp"
#include "Utils.hpp"
#include <iostream>

using namespace std;

EnemyStruct *getEnemies(bool mode) {
    EnemyHandler enemyHandler;

    string modeModifier = mode ? "rpg" : "clt";
    string path = "./src/data/" + modeModifier + ".enemy.csv";

    int enemyCount = 0;

    // Converte string para const char* usando .c_str()
    EnemyStruct *enemies = enemyHandler.generateEnemiesArray(path.c_str(), enemyCount);
    return enemies;
}


PotionStruct *getPotions(bool mode) {
    PotionHandler potionHandler;
    string modeModifier = mode ? "rpg" : "clt";

    string path = "./src/data/" + modeModifier + ".potion.csv";

    int potionCount = 0;

    // Gera o array de poções e retorna
    PotionStruct *potions = potionHandler.generatePotionsArray(path.c_str(), potionCount);
    return potions;
}

WeaponStruct *getWeapons(bool mode) {
    WeaponHandler weaponHandler;
    string modeModifier = mode ? "rpg" : "clt";

    string path = "./src/data/" + modeModifier + ".weapon.csv";

    int weaponCount = 0;

    // Gera o array de armas e retorna
    WeaponStruct *weapons = weaponHandler.generateWeaponsArray(path.c_str(), weaponCount);
    return weapons;
}

Weapon *GenRandomWeapon(WeaponStruct *weapons, int level) {
    int random = rand() % 50;
    WeaponStruct weapon = weapons[random];

    // Modificador ajustado: deteriora o valor base até o nível 40
    double modifier = (level <= 40)
        ? 1 - 0.5 * (1 - (level / 40.0))  // Deterioração progressiva até o nível 40
        : 0.5 * ((level - 40) / 100.0);   // Aumento progressivo após o nível 40

    weapon.attackPower *= modifier;
    weapon.attackPower += (level / 5 * 2);  // Bônus adicional baseado no nível

    return new Weapon(weapon);
}

Potion *GenRandomPotion(PotionStruct *potions, int level) {
    int random = rand() % 50;
    PotionStruct potion = potions[random];
    
    double modifier = (level <= 40)
        ? 1 - 0.5 * (1 - (level / 40.0))  
        : 0.5 * ((level - 40) / 100.0);  

    potion.healingPower *= modifier;
    potion.healingPower += (level / 5 * 2);

    return new Potion(potion);
}

Enemy *GenRandomEnemy(EnemyStruct *enemies, int level) {
    int random = rand() % 50;
    EnemyStruct enemy = enemies[random];

    double modifier = (level <= 40)
        ? 1 - 0.5 * (1 - (level / 40.0))  
        : 0.5 * ((level - 40) / 100.0);  

    enemy.attackPower *= modifier;
    enemy.attackPower += (level / 5 * 2);

    enemy.maxHealth *= modifier;
    enemy.maxHealth += (level / 5 * 2);

    return new Enemy(enemy);
}
