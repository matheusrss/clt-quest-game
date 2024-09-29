#include "Map.hpp"
#include "Enemy.hpp"
#include "Utils.hpp"
#include "Weapon.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

// Implementacões genéricas da classe template Map
template <typename T>
void Map<T>::trigger(void *obj) {
    T *typedObj = static_cast<T *>(obj);
}

template <typename T>
void Map<T>::displayMap(void *obj) const {
    T *typedObj = static_cast<T *>(obj);
}

// Especializacão para Map<Enemy>
void handleEnemyMap(Enemy *enemy, Hero *hero); // Declaração antes de ser usada
template <>
void Map<Enemy>::trigger(void *obj) {
    Enemy *enemy = static_cast<Enemy *>(obj);
    Hero *maphero = hero;

    handleEnemyMap(enemy, maphero);
}

template <>
void Map<Enemy>::displayMap(void *obj) const {
    Enemy *enemy = static_cast<Enemy *>(obj);
    string message = "Voce encontrou um feroz inimigo";
    displayInterface(message, this->getHero(), "Enemy", enemy);
}

// Especializacão para Map<Weapon>|
template <>
void Map<Weapon>::trigger(void *obj) {
    Weapon *weapon = static_cast<Weapon *>(obj);
    Hero *maphero = hero;

    handleItemMap(weapon, maphero);
}

template <>
void Map<Weapon>::displayMap(void *obj) const {
    Weapon *item = static_cast<Weapon *>(obj);
    string message = "Voce encontrou um(a) " + item->getPrefix() + " " + item->getName() + " " + item->getSuffix() + "\nDescricao: " + item->getDescription() + "\n Tem " + to_string(item->getAttackPower()) + " De dano";

    displayInterface(message, this->getHero(), "Treasure");
}

template <>
void Map<Potion>::trigger(void *obj) {
    Potion *potion = static_cast<Potion *>(obj);
    Hero *maphero = hero;

    handleItemMap(potion, maphero);

    return;
}

template <>
void Map<Potion>::displayMap(void *obj) const {
    Potion *item = static_cast<Potion *>(obj);
    string message = "Voce encontrou um(a) " + item->getPrefix() + " " + item->getName() + " " + item->getSuffix() + "\n\nDescricao: " + item->getDescription() + "\n Tem a capacidade curativa de " + to_string(item->getHealingPower());
    displayInterface(message, this->getHero(), "Potion");
}

void Map<void>::trigger(void *) {
    Hero *maphero = hero;

    handleVoidMap(maphero);
}

void Map<void>::displayMap(void *) const {
    string message = "Voce encontrou uma sala completamente vazia.\n voce aproveita o momento e se deita para descansar, recuperando completamente a vida";
    hero->healFullLife();
    displayInterface(message, this->getHero(), "Void");
}

// Instanciacão explícita
template class Map<Item>;
template class Map<Weapon>;
template class Map<Potion>;
template class Map<Enemy>;
template class Map<void>;
