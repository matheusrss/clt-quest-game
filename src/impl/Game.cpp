#include "Game.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Enemy.hpp"
#include "Item.hpp"
#include "Potion.hpp"
#include "Utils.hpp"
#include "Weapon.hpp"

#include "FileHandler.hpp"

#include "scores.hpp"

using namespace std;


Game::Game(Hero *hero, int mode) : hero(hero), currentMap(nullptr) {
    srand(static_cast<unsigned>(time(0)));
    this->level = 1;
    this->score = 0;
    this->mode = mode;

    this->enemies = getEnemies(this->mode);
    this->weapons = getWeapons(this->mode);
    this->potions = getPotions(this->mode);
}

void Game::changeMap(MapInterface *newMap) {
    if (currentMap != nullptr) {
        delete currentMap;
    }
    this->currentMap = newMap;
    this->level++;

    if (this->level > 2) {
        int percentage;

        percentage = (this->level / 5) * 2;
        int lifeBuff = 1 + (percentage / 100.0f);
        hero->increaseHealth(lifeBuff);

        percentage = (this->level / 10) * 5;
        int damageBuff = 1 + (percentage / 100.0f);
        hero->increaseBaseDamage(damageBuff);
    }
}

void Game::start() {
    // Primeira sala com uma arma aleatória
    Weapon *randomWeapon = GenRandomWeapon(weapons, this->level);
    Map<Weapon> *weaponMap = new Map<Weapon>(hero);

    changeMap(weaponMap); // Muda para o mapa da arma
    weaponMap->displayMap(randomWeapon);
    weaponMap->trigger(randomWeapon); // Dispara o evento da arma

    // Segunda sala com inimigo
    Enemy *enemy = GenRandomEnemy(enemies, this->level);
    Map<Enemy> *enemyMap = new Map<Enemy>(hero);

    changeMap(enemyMap);         // Muda para o mapa do inimigo
    enemyMap->displayMap(enemy); // Exibe o mapa após o encontro com o inimigo
    enemyMap->trigger(enemy);    // Dispara o evento de combate

    // Loop principal do jogo, sem contadores
    while (hero->isAlive()) {
        int randomValue = rand() % 10 + 1; // Gera um número entre 1 e 10

        if (randomValue <= 5) {
            // 50% de chance de encontrar um inimigo
            Enemy *newEnemy = GenRandomEnemy(enemies, this->level);
            Map<Enemy> *newEnemyMap = new Map<Enemy>(hero);

            changeMap(newEnemyMap);            // Muda para o mapa do novo inimigo
            newEnemyMap->displayMap(newEnemy); // Exibe o mapa após o encontro com o inimigo
            newEnemyMap->trigger(newEnemy);    // Dispara o evento de combate

            increaseScore(newEnemy->getAttackPower(), newEnemy->getMaxHealth());
        } 
        else if (randomValue <= 9) {
            // 40% de chance de encontrar itens (poções ou armas)
            bool isPotion = (rand() % 4 != 0); // 75% de chance de ser poção, 25% de chance de ser arma

            if (isPotion) {
                Potion *potion = GenRandomPotion(potions, this->level);
                Map<Potion> *newMap = new Map<Potion>(hero);
                changeMap(newMap);

                newMap->displayMap(potion);
                newMap->trigger(potion);
            } else {
                Weapon *weapon = GenRandomWeapon(weapons, this->level);
                Map<Weapon> *newMap = new Map<Weapon>(hero);
                changeMap(newMap);

                newMap->displayMap(weapon);
                newMap->trigger(weapon);
            }
        } 
        else {
            // 10% de chance de encontrar uma sala vazia
            Map<void> *emptyMap = new Map<void>(hero);
            changeMap(emptyMap);    // Muda para a sala vazia
            emptyMap->displayMap(); // Exibe o mapa após entrar na sala vazia
            emptyMap->trigger();    // Dispara o evento da sala vazia
        }
    }
}


void Game::displayCurrentMap() const {
    if (currentMap != nullptr) {
        currentMap->displayMap();
    } else {
        cout << "Nenhum mapa selecionado.\n";
    }
}

void Game::increaseScore(double enemyAttack, double health) {
    int total = static_cast<int>(enemyAttack) + static_cast<int>(health);

    this->score += total;
}

void Game::end() {
    string name = hero->getName();
    addAndSortScores(name, level, score);
}

Game::~Game() {
    if (currentMap != nullptr) {
        delete currentMap;
    }
}
