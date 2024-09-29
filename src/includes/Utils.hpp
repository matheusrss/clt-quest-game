#ifndef UTILS_HPP
#define UTILS_HPP

#include "Weapon.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"
#include "FileHandler.hpp"

// Declaracão das funcões utilitarias
void handleBeltStorage(Weapon *weapon, Hero *hero);
void handleBeltStorage(Potion *potion, Hero *hero);

void handleWeaponStorage(Weapon *weapon, Hero *hero);
void handlePotionStorage(Potion *potion, Hero *hero);
void handleBeltUsage(Hero *hero);
void handleBeltDelete(Hero *hero);
void handleBackpack(Hero *hero);
bool isValidChoice(int choice);
int makeChoice();

void handleItemMap(Weapon *weapon, Hero *hero);
void handleItemMap(Potion *potion, Hero *hero);
void handleEnemyMap(Enemy* enemy, Hero* hero);
void handleVoidMap(Hero* maphero);

void sleep(int seconds);

void displayInterface(const string& message, const Hero* hero, string type, const Enemy* enemy = nullptr);

void displayCommands(string type);

void clearScreen();

EnemyStruct* getEnemies(bool mode);
PotionStruct* getPotions(bool mode);
WeaponStruct* getWeapons(bool mode);


Weapon *GenRandomWeapon(WeaponStruct *weapons, int level);
Potion *GenRandomPotion(PotionStruct *potions, int level);
Enemy *GenRandomEnemy(EnemyStruct *enemy, int level);


#endif