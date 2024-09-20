#include "Enemy.hpp"
#include <iostream>

using namespace std;

// Construtor da classe enemy "OOOO THE MISERY"
Enemy::Enemy(string name, double maxHealth, double attackPower, string description)
    :Character (name, attackPower){ // Inicia com Character como base, declarando nome e vida.
        this -> attackPower = attackPower; // Atribui o dano do inimigo
        this -> description = description; // Atibui a descrição do inimigo
 }

// Função que faz o inimigo atacar um alvo
void Enemy::attack(Character* target){
    if(target == NULL){ // Verificação se o alvo é valido
        cout << "Alvo invalido" << endl;
    }
    cout << name << "Atacou " << target -> getName() << "dando " << attackPower << " de dano!" << endl;
    target -> takeDamage(attackPower); // Aplica o dano no alvo declarado (Normalmente o player)
}

// Função que retorna a descrição do inimigo
string Enemy::getDescription() const{
    return description;
}

// Função que retorna o dano do inimigo
double Enemy::getAttackPower() const {
    return attackPower;
}

// Destrutor
Enemy::~Enemy(){
}



