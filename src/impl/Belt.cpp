#include "Belt.hpp"
#include "Item.hpp"
#include <iostream>

using namespace std;

Belt::Belt(double maxWeightPerSlot) {
    this->maxWeightPerSlot = maxWeightPerSlot;
    head = nullptr; 
    slotCount = 0; 
}

// Funcão para adicionar item ao cinto
bool Belt::addItemToSlot(Item* item, int slot) {
    if (slot < 1 || slot > 5) {
        cout << "Slot invalido! Deve ser entre 1 e 5." << endl;
        return false;
    }

    if (item->getWeight() > maxWeightPerSlot) {
        cout << "Item excede o peso maximo permitido neste espaco." << endl;
        return false;
    }

    Node* newNode = new Node();
    newNode->item = item;
    newNode->next = nullptr;

    if (slotCount == 0) {
        head = newNode;
        slotCount++;
        return true;
    }

    if (slot == 1) {
        if (head != nullptr) {
            newNode->next = head;
        }
        head = newNode;
        slotCount++;
        return true;
    }

    Node* current = head;
    Node* prev = nullptr;
    for (int i = 1; i < slot - 1 && current != nullptr; i++) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Slot original invalido. Realocando para o proximo slot disponivel." << endl;
        if (prev == nullptr) {
            newNode->next = head;
            head = newNode;
        } else {
            newNode->next = prev->next;
            prev->next = newNode;
        }
    } else if (current->next != nullptr) {
        cout << "Slot ocupado! Realocando itens subsequentes." << endl;
        newNode->next = current->next;
        current->next = newNode;
    } else {
        current->next = newNode;
    }

    slotCount++;
    return true;
}

// Funcão para remover item do slot
Item* Belt::removeItemFromSlot(int slot) {
    // O índice dos slots comeca em 1 e vai até 5
    if (slot < 1 || slot > 5 || head == nullptr) {
        cout << "Slot invalido ou cinto vazio!" << endl;
        return nullptr;
    }

    Node* temp;
    if (slot == 1) {
        temp = head;
        head = head->next;
    } else {
        Node* current = head;
        for (int i = 1; i < slot - 1 && current->next != nullptr; i++) {
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << "Slot invalido!" << endl;
            return nullptr;
        }

        temp = current->next;
        current->next = temp->next;
    }

    Item* removedItem = temp->item;
    delete temp;
    slotCount--;
    return removedItem;
}

// Funcão para obter um item de um slot específico
Item* Belt::getItemFromSlot(int slot) const {
    // O índice dos slots comeca em 1 e vai até 5
    if (slot < 1 || slot > 5) {
        return nullptr;
    }

    Node* current = head;
    for (int i = 1; i < slot && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        return nullptr;
    }

    return current->item;
}

// Funcão para obter o peso maximo por slot
double Belt::getMaxWeightPerSlot() const {
    return maxWeightPerSlot;
}

// Destrutor
Belt::~Belt() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
