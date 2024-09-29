#include "Character.hpp"
#include <iostream>

using namespace std;

// Construtor do personagem
Character::Character(string name, double maxHealth) {
    this->name = name;               // Atribui nome ao personagem
    this->maxHealth = maxHealth;     // Atribui a vida maxima
    this->currentHealth = maxHealth; // Faz com que o personagem inicie com vida maxima
}

// Retorna o nome do personagem
string Character::getName() const {
    return name;
}

// Retorna a vida maxima do personagem
double Character::getMaxHealth() const {
    return maxHealth;
}

// Retorna a vida atual do personagem
double Character::getCurrentHealth() const {
    return currentHealth;
}

// Metodo para aplicar dano ao personagem
void Character::takeDamage(double damage) {
    currentHealth -= damage; // Subtrai a quantidade de dano na vida do personagem
    if (currentHealth < 0)
        currentHealth = 0; // Método para não deixar a vida do personagem ser menor que 0 "MORRE PORRA"
    cout << name << " Tomou " << damage << " de dano!" << endl;
}

// Metodo para aplicar cura ao personagem
void Character::heal(double amount) {
    currentHealth += amount; // Adiciona a quantidade de cura a vida do personagem
    if (currentHealth > maxHealth) {
        currentHealth = maxHealth; // Método para não deixar que a vida exeda o valor maximo "VIVA! Mas com limites..."
    }
    cout << name << " Se curou em:" << amount << "!" << endl;
    cout << "Vida atual: " << currentHealth << endl;
}

// Destrutor
Character::~Character() {
}

bool Character::isAlive() const {
    return currentHealth > 0;  // Corrigido: retorna true se a vida for maior que 0
}
