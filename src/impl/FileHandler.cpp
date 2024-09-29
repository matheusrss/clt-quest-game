#include "FileHandler.hpp"
#include <fstream>
#include <sstream>
#include <iostream>


int EnemyHandler::readEnemies(const char* filename, EnemyStruct* enemies) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return 0;
    }

    string line;
    getline(file, line);

    int count = 0;
    while (getline(file, line) && count < MAX_ENEMIES) {
        stringstream ss(line);
        getline(ss, enemies[count].name, ',');
        ss >> enemies[count].maxHealth;
        ss.ignore(1);  // Ignora a vírgula
        ss >> enemies[count].attackPower;
        ss.ignore(1);  // Ignora a vírgula
        getline(ss, enemies[count].description, ',');
        count++;
    }

    file.close();
    return count;
}

EnemyStruct* EnemyHandler::generateEnemiesArray(const char* filename, int& enemyCount) {
    EnemyStruct* enemies = new EnemyStruct[MAX_ENEMIES];
    enemyCount = readEnemies(filename, enemies);
    return enemies;
}

int PotionHandler::readPotions(const char* filename, PotionStruct* potions) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return 0;
    }

    string line;
    getline(file, line); 

    int count = 0;
    while (getline(file, line) && count < MAX_POTIONS) {
        stringstream ss(line);
        getline(ss, potions[count].name, ',');
        ss >> potions[count].weight;
        ss.ignore(1);  
        ss >> potions[count].healingPower;
        ss.ignore(1);  
        getline(ss, potions[count].description, ',');
        getline(ss, potions[count].prefix, ',');
        getline(ss, potions[count].suffix, ',');
        count++;
    }

    file.close();
    return count;
}

PotionStruct* PotionHandler::generatePotionsArray(const char* filename, int& potionCount) {
    PotionStruct* potions = new PotionStruct[MAX_POTIONS];
    potionCount = readPotions(filename, potions);
    return potions;
}

int WeaponHandler::readWeapons(const char* filename, WeaponStruct* weapons) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return 0;
    }

    string line;
    getline(file, line); 

    int count = 0;
    while (getline(file, line) && count < MAX_WEAPONS) {
        stringstream ss(line);
        getline(ss, weapons[count].name, ',');
        ss >> weapons[count].weight;
        ss.ignore(1); 
        ss >> weapons[count].attackPower;
        ss.ignore(1);  
        getline(ss, weapons[count].description, ',');
        getline(ss, weapons[count].prefix, ',');
        getline(ss, weapons[count].suffix, ',');
        count++;
    }

    file.close();
    return count;
}

WeaponStruct* WeaponHandler::generateWeaponsArray(const char* filename, int& weaponCount) {
    WeaponStruct* weapons = new WeaponStruct[MAX_WEAPONS];
    weaponCount = readWeapons(filename, weapons);
    return weapons;
}
