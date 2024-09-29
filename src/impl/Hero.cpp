#include "Hero.hpp"
#include <iostream>

using namespace std;

// Construtor da classe heroi
Hero::Hero(string name, double maxHealth, double maxWeightPerSlot) : Character(name, maxHealth),
                                                                     belt(maxWeightPerSlot) { // Mochila inicada automaticamente e cinto
                                                                                              // iniciado com o peso maximo permitido
    this->baseDamage = 35;
    this->currentWeapon = nullptr;
}

// Implementacão de ataque
void Hero::attack(Character *target) {
    if (target == nullptr) {
        cout << "Nenhum alvo para atacar." << endl;
        return;
    }

    double damage = this->getBaseDamage();      // Dano basico do herói
    Weapon *equippedWeapon = this->getWeapon(); // Arma equipada

    if (equippedWeapon) {                           // Verifica se ha arma equipada
        damage += equippedWeapon->getAttackPower(); // Adiciona o dano da arma ao ataque
        cout << name << " atacou " << target->getName()
             << " usando um(a) " << equippedWeapon->getPrefix()
             << " " << equippedWeapon->getName()
             << " causando " << damage << " de dano!" << endl;
    } else {
        cout << name << " atacou " << target->getName()
             << " desarmado, causando " << damage << " de dano!" << endl;
    }

    target->takeDamage(damage); // Aplica dano ao alvo
}

// Implementacão da descricão do protagonista
string Hero::getDescription() const {
    return "Heroi " + name + "Vida: " + to_string(currentHealth) + " / " +
           to_string(maxHealth);
}

// Funcão para adicionar um item a mochila
void Hero::addItemToBackpack(Item *item) {
    if (item == nullptr) { // Verificacão se o item é um item valido
        cout << "Item invalido!" << endl;
    }
    if (backpack.addItem(item)) { // Tenta adicionar item na mochila com o
                                  // método addItem() da classe Backpack
        cout << "Item: " << item->getName() << " adicionado na mochila." << endl;
    }
}

// Funcão para adionar item ao slot do cinto
void Hero::addItemToBelt(Item *item, int slot) {
    if (item == nullptr) {
        cout << "Item invalido!" << endl;
        return;
    }

    if (belt.addItemToSlot(item, slot)) {

        cout << "Item: " << item->getName() << " adicionado ao cinto, no slot " << slot << endl;
    } else {
        cout << "Nao e possivel adicionar item ao cinto!" << endl;
    }
}

// Funcão para pegar o último item da mochila
Item *Hero::getItemFromBackpack() const {
    Item *item = backpack.getLastItem();
    if (item != nullptr) { // Verifica se o slot é diferente de vazio
        cout << "Ultimo item na mochila: " << item->getName() << endl;
    } else {
        cout << "Mochila vazia!" << endl;
    }
    return item;
}

// Funcão para pegar item no slot do cinto
// Funcão para obter item do cinto
Item *Hero::getItemFromBelt(int slot) const {
    Item *item = belt.getItemFromSlot(slot);
    return item;
}

Item *Hero::removeItemFromBackpack() {
    Item *item = backpack.removeItem();
    if (item) {
        cout << "Item removido da mochila: " << item->getName() << endl;
    } else {
        cout << "A mochila esta vazia!" << endl;
    }
    return item;
}

Weapon *Hero::getWeapon() const { return currentWeapon; }

void Hero::equipWeapon(Weapon *weapon) {
    if (weapon == nullptr) {
        cout << "Nenhuma arma foi equipada!" << endl;
        return;
    }

    currentWeapon = weapon; // Simplesmente altera a referência sem deletar
    cout << name << " equipou " << weapon->getName() << "." << endl;
}

int Hero::getBaseDamage() const { return baseDamage; }

Item *Hero::removeItemFromBelt(int slot) {
    // Chama a funcão correspondente do cinto (Belt) para remover o item do slot
    Item *removedItem = belt.removeItemFromSlot(slot);

    if (removedItem != nullptr) {
        cout << "Item removido do slot " << slot << ": " << removedItem->getName() << endl;
    } else {
        cout << "Nenhum item removido do slot " << slot << endl;
    }

    return removedItem;
}

void Hero::increaseBaseDamage(double percentage) {
    baseDamage *= percentage;
}

void Hero::increaseHealth(double percentage) {
    maxHealth *= percentage;
}

void Hero::healFullLife() {
    currentHealth = maxHealth;
}


// Destrutor
Hero::~Hero() { cout << "O Personagem " << name << " Foi destruido da historia. Suas Consquistas nao serao esquecidas" << endl; }