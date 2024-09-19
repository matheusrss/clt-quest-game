#include "Belt.hpp"
#include "Item.hpp"
#include <iostream>

using namespace std;

// Construtor do cinto com o peso máximo por slot
Belt::Belt(double maxWeightPerSlot){
    this -> maxWeightPerSlot = maxWeightPerSlot; // Define o valor máximo de peso por slot do cinto
    head = NULL; // Cinto começa vazio
    slotCount = 0; // Numeró máximo de slots que o cinto possui
}

// Função para adiconar item ao cinto
bool Belt::addItemToSlot(Item* item, int slot){
    if(item -> getWeight() > maxWeightPerSlot){ // Verifica se o peso do item é maior que o peso permitodo no espaço
        cout << "Item excede o peso maximo permitido neste espaco" << endl;
        return false;
    }
    // Cria um novo nó para armazenar o item
    Node* newNode = new Node();
    newNode -> item = item; // Novo nó armazena o item
    newNode -> next = NULL; // Define o próximo nó como vazio

    if(head == NULL){ // Verifica se o cinto está vazio
        head = newNode; // Novo nó se torna o primeiro da lista
        slotCount ++; // Aumenta o número do contador de itens
        return true;
    }

    if(slot == 0){ // Se o slot atibuido for 0, coloca no primeiro espaço
        newNode -> next = head; // Novo nó aponta para o inicio da lista
        head = newNode; 
        slotCount ++;
        return true;
    }

    // Percore a lista de espaços até o espaço desejado
    Node* current = head; // Começa no head
    for (int i = 0; i < slot - 1 && current -> next != NULL; i ++){
        current = current -> next; // Vai para o próximo nó
    }

    if (current != NULL && current -> item != NULL){ // Verifica se o slot ja está ocupado
        cout << "Slot ocupado" << endl;
        return false;
    }

    newNode -> next = current -> next;
    current -> next = newNode;
    slotCount ++;
    return true;
}

Item* Belt::removeItemFromSlot(int slot){
    if(head == NULL){
        cout << "Cinto vazio!" << endl;
        return NULL;
    }

    Node* temp;
    if(slot == 0){
        temp = head;
        head = head -> next;
    }else{
        Node* current = head;
        for(int i = 0; i < slot -1 && current -> next != NULL; i++){
            current = current -> next;
        }
        if(current -> next == NULL){
            cout << "Slot invalido!" << endl;
            return NULL;
        }

        temp = current -> next;
        current -> next = temp -> next;
    }

    Item* removedItem = temp -> item;
    delete temp;
    slotCount --;
    return removedItem;
}

Item* Belt::getItemFromSlot(int slot) const{
    if (head == NULL){
        cout << "Cinto vazio!" << endl;
        return NULL;
    }

    Node* current = head;
    for(int i = 0; i < slot && current != NULL; i++){
        current = current -> next;
    }

    if(current == NULL){
        cout << "Slot invalido!" << endl;
        return NULL;
    }

    return current -> item;
}

double Belt::getMaxWeightPerSlot() const{
    return maxWeightPerSlot;
}

Belt::~Belt(){
    Node* current = head;
    while (current != NULL){
        Node* next = current -> next;
        delete current;
        current = next;
    }
}

