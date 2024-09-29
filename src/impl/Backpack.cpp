#include "Backpack.hpp"
#include <iostream>

using namespace std;

// Construtor que inicia a mochila vazia
Backpack::Backpack() {
    top = nullptr;
}

// Adiconar item na pilha
bool Backpack::addItem(Item *newItem) {
    Node *newNode = new Node; // Cria um novo nó para colocar na pilha
    if (newNode == nullptr) { // Verificacão se o novo nó foi alocado em nullptr
        cout << "Erro de alocacao!" << endl;
        return false;
    }
    newNode->item = newItem; // Atribui o item ao campo 'item' no novo nó
    newNode->next = top;     // O próximo nó desse novo nó sera o antigo topo
    top = newNode;           // Atualiza o topo para que o novo nó seja o novo topo da pilha
    return true;
}

// Remove item da pilha
Item *Backpack::removeItem() {
    if (top == nullptr) { // Verificacão se a mochila esta vazia
        cout << "Mochila vazia!" << endl;
        return nullptr;
    }
    Node *temp = top;               // Armazenamento temporario do nó do topo
    Item *removedItem = temp->item; // Armazena o item que esta no topo
    top = top->next;                // Atualiza o topo da pilha para o próximo nó
    delete temp;                    // Deleta o armazenamento temporario
    return removedItem;             // Retorna item removido
}

// Obtem o item no topo da pilha sem remover
Item *Backpack::getLastItem() const {
    if (top == nullptr) {
        return nullptr;
    }
    return top->item;
}

// Conta quando itens tem na pilha
int Backpack::getItemCount() const {
    int count = 0;               // Contador dos itens
    Node *current = top;         // Comeca a contagem a partir do topo da pilha
    while (current != nullptr) { // Percorre a pilha enquanto current for diferente de nullptr
        count++;                 // Adiciona +1 ao valor do contador
        current = current->next; // Move current para o próximo nó
    }
    return count;
}

// Destrutor
Backpack::~Backpack() {
    while (top != nullptr) {
        removeItem();
    }
}
