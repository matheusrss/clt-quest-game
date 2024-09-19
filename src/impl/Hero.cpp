#include "Hero.hpp"
#include <iostream>

using namespace std;

// Construtor da classe heroi
Hero::Hero(string name, double maxHealth, double maxWeightPerSlot)
   : Character(name, maxHealth), belt(maxWeightPerSlot){ // Mochila inicada automaticamente e cinto iniciado com o peso máximo permitido
   }

    // Implementação de ataque
    void Hero::attack(Character* target){
        if(target == NULL){ // Verifica se tem alvo válido para atacar
            cout << "Nenhum alvo para atacar." << endl;
            return;
    }
    double damage = 1.0; // Dano padrão 
    cout << name << "atacou " << target -> getName() << "causando " << damage << " de dano!" << endl;
    target -> takeDamage(damage); // Faz com que o alvo tome dano
}

// Implementação da descrição do protagonista
string Hero::getDescription() const{
    return "Heroi " + name + "Vida: " + to_string(currentHealth) + " / " + to_string(maxHealth);
}

// Função para adicionar um item a mochila
void Hero::addItemToBackpack(Item* item){
    if(item == NULL){ // Verificação se o item é um item válido
        cout << "Item invalido!" << endl;
    }
    if(backpack.addItem(item)){ // Tenta adicionar item na mochila com o método addItem() da classe Backpack
        cout << "Item: " << item -> getName() << "adicionado na mochila." << endl;
    }
}

// Função para adionar item ao slot do cinto
void Hero::addItemToBelt(Item* item, int slot){
    if(item == NULL){ // Verificação se o tem é válido
        cout << "Item invalido!" << endl;
    }
    if(belt.addItemToSlot(item, slot)){
        cout << "Item: " << item -> getName() << "adicionado ao cinto, no slot " << slot << endl;
    }else{
        cout << "Nao e possivel adicionar item ao cinto! " << endl;
    }
}

//Função para pegar o último item da mochila
Item* Hero::getItemFromBackpack() const{
    Item* item = backpack.getLastItem();
    if(item != NULL){ // Verifica se o slot é diferente de vazio
       cout << "Ultimo item na mochila: " << item -> getName()<< endl;
    }else{
        cout << "Mochila vazia!" << endl;
    }
    return item;
}

// Função para pegar item no slot do cinto
Item* Hero::getItemFromBelt(int slot) const{
    Item* item = belt.getItemFromSlot(slot);
    if(item != NULL){ 
       cout << "Item no slot " << slot << "do cinto: " << item -> getName()<< endl;
    }else{
        cout << "Slot " << slot << " vazio!" << endl;
    }
    return item;
}

// Destrutor
Hero::~Hero(){
    cout << "Personagem " << name << "apagado." << endl;
}