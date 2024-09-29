#include "Enemy.hpp"
#include "FileHandler.hpp"
#include <iostream>

using namespace std;

// Construtor da classe enemy "OOOO THE MISERY"
Enemy::Enemy(string name, double maxHealth, double attackPower, string description) : Character(name, maxHealth) {
    // Inicia com Character como base, declarando nome e vida.
    this->attackPower = attackPower; // Atribui o dano do inimigo
    this->description = description; // Atibui a descricão do inimigo
}

Enemy::Enemy(EnemyStruct enemy): Character(enemy.name, enemy.maxHealth) {
    this->attackPower = enemy.attackPower;
    this->description = enemy.description;
}

// Funcão que faz o inimigo atacar um alvo
void Enemy::attack(Character *target) {
    if (target == nullptr) { // Verificacão se o alvo é valido
        cout << "Alvo invalido" << endl;
    }
    cout << name << " Atacou " << target->getName() << " dando " << attackPower << " de dano!" << endl;
    target->takeDamage(attackPower); // Aplica o dano no alvo declarado (Normalmente o player)
}

// Funcão que retorna a descricão do inimigo
string Enemy::getDescription() const {
    return description;
}

// Funcão que retorna o dano do inimigo
double Enemy::getAttackPower() const {
    return attackPower;
}

// Destrutor
Enemy::~Enemy() {
}
