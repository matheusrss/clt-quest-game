#include "Utils.hpp"
#include <iostream>

#include "Enemy.hpp"
#include "Hero.hpp"
#include "Potion.hpp"
#include "Weapon.hpp"

#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

void clearScreen() {
#ifdef __linux__
    system("clear");
#else
    system("cls");
#endif
}

void displayCommands(string type) {
    if (type == "Void") {
        cout << "\n";
        cout << "=============================\n";
        cout << "Available Commands:\n";
        cout << "1. Abrir bolsa\n";
        cout << "2. Usar item do cinto\n";
        cout << "3. Avancar\n";
        cout << "=============================\n";
        return;
    }

    if (type == "Potion") {
        cout << "\n";
        cout << "=============================\n";
        cout << "Available Commands:\n";
        cout << "1. Recolher a pocao\n";
        cout << "2. Descartar a pocao\n";
        cout << "3. Usar item do cinto\n";
        cout << "4. Abrir bolsa\n";
        cout << "5. Remover item do cinto\n";
        cout << "5. Avancar(descarta o loot se nao for pego)\n";
        cout << "=============================\n";
        return;
    }

    if (type == "Treasure") {
        cout << "\n";
        cout << "=============================\n";
        cout << "Available Commands:\n";
        cout << "1. Recolher a arma\n";
        cout << "2. Descartar a arma\n";
        cout << "3. Usar item do cinto\n";
        cout << "4. Abrir bolsa\n";
        cout << "5. Remover item do cinto\n";
        cout << "6. Avancar(descarta o loot se nao for pego)\n";
        cout << "=============================\n";
        return;
    }

    cout << "\n";
    cout << "=============================\n";
    cout << "Available Commands:\n";
    cout << "1. Atacar\n";
    cout << "2. Abrir bolsa\n";
    cout << "3. Usar item do cinto\n";
    cout << "=============================\n";
}

void displayInterface(const string &message, const Hero *hero, string type, const Enemy *enemy) {
    clearScreen();
    cout << "=========================================================\n";
    cout << "| " << message << "\n";
    cout << "=========================================================\n";

    // Enemy details
    if (enemy) {
        cout << "----------------- Enemy Encounter -----------------------\n";
        cout << "| Enemy: " << enemy->getName() << "\n";
        cout << "| HP: " << enemy->getCurrentHealth() << "/" << enemy->getMaxHealth() << "\n";
        cout << "| Description: " << enemy->getDescription() << "\n";
        cout << "---------------------------------------------------------\n";
    }

    // Hero details
    Weapon *equipedWeapon = hero->getWeapon();
    string equipedWeaponName = equipedWeapon ? equipedWeapon->getName() : "Desarmado";
    int weaponDamage = equipedWeapon ? equipedWeapon->getAttackPower() : 0;
    int totalDamage = hero->getBaseDamage() + weaponDamage; // Calculo do dano total

    cout << "----------------- Hero Status ---------------------------\n";
    cout << "| " << hero->getName() << " HP: " << hero->getCurrentHealth() << "/" << hero->getMaxHealth() << "\n";
    cout << "| Weapon: " << equipedWeaponName << " (Weapon Damage: " << weaponDamage << ")\n";
    cout << "| Total Damage: " << totalDamage << " (Base Damage: " << hero->getBaseDamage() << " + Weapon Damage: " << weaponDamage << ")\n";
    cout << "---------------------------------------------------------\n";

    // Belt details (slots and items)
    cout << "----------------- Belt Inventory ------------------------\n";
    for (int i = 0; i < 5; ++i) {
        Item *item = hero->getItemFromBelt(i + 1);
        if (item) {
            cout << "| Slot " << (i + 1) << ": " << item->getName();
            if (Weapon *weapon = dynamic_cast<Weapon *>(item)) {
                cout << " (Damage: " << weapon->getAttackPower() << ")";
            } else if (Potion *potion = dynamic_cast<Potion *>(item)) {
                cout << " (Heals: " << potion->getHealingPower() << ")";
            }
        } else {
            cout << "| Slot " << (i + 1) << ": [Empty]";
        }
        cout << "\n";
    }
    cout << "---------------------------------------------------------\n";
    // Display commands based on the type (combat, explore, etc.)
    displayCommands(type);

    cout << endl;
}

void handleBeltStorage(Weapon *weapon, Hero *hero) {
    cout << "Escolha um slot de 1 a 5 para guardar a arma: ";
    int beltPos;
    cin >> beltPos;

    if (beltPos < 1 || beltPos > 5) {
        cout << "posicao invalida!!";
        return;
    }

    Weapon *newWeapon = new Weapon(*weapon);
    cout << endl
         << newWeapon->getName() << endl;
    hero->addItemToBelt(newWeapon, beltPos);
}

void handleBeltStorage(Potion *potion, Hero *hero) {
    cout << "Escolha um slot de 1 a 5 para guardar a arma: ";
    int beltPos;
    cin >> beltPos;

    if (beltPos < 1 || beltPos > 5) {
        cout << "posicao invalida!!";
        return;
    }

    Potion *newPotion = new Potion(*potion);
    cout << endl
         << newPotion->getName() << endl;
    hero->addItemToBelt(newPotion, beltPos);
}

void handleWeaponStorage(Weapon *weapon, Hero *hero) {
    cout << "voce ira colocar a arma no cinto(1) ou na bolsa(2)? ";
    int bagChoice;
    cin >> bagChoice;

    Weapon *newWeapon = new Weapon(*weapon);

    if (bagChoice == 1) {
        handleBeltStorage(newWeapon, hero);
        return;
    }

    hero->addItemToBackpack(newWeapon);
}

void handlePotionStorage(Potion *potion, Hero *hero) {
    cout << "voce ira colocar a pocao no cinto(1) ou na bolsa(2)? ";
    int bagChoice;
    cin >> bagChoice;

    if (bagChoice == 1) {
        handleBeltStorage(potion, hero);
        return;
    }

    hero->addItemToBackpack(potion);
}

void handleBeltUsage(Hero *hero) {
    cout << "Escolha a posicao do cinto que deseja usar!\n";
    cout << "Usar uma arma substituira a arma equipada pela posicao do cinto\n";
    cout << "Usar uma pocao aplicara os efeitos imediatamente! \n";

    int beltPos;
    cin >> beltPos;

    if (beltPos < 1 || beltPos > 5) {
        cout << "posicao invalida!";
        return;
    }

    Item *item = hero->getItemFromBelt(beltPos);

    if (Potion *potion = dynamic_cast<Potion *>(item)) {
        hero->heal(potion->getHealingPower());
        Item *item = hero->removeItemFromBelt(beltPos);
        delete item;
        return;
    }

    if (Weapon *weapon = dynamic_cast<Weapon *>(item)) {
        Weapon *equippedWeapon = hero->getWeapon();
        hero->equipWeapon(weapon);
        hero->removeItemFromBelt(beltPos);

        if (equippedWeapon) {
            hero->addItemToBelt(equippedWeapon, beltPos);
        }
    }
}

void handleBeltDelete(Hero *maphero) {
    cout << "Escolha a posicao do cinto que deseja deletar!\n";
    int beltPos;
    cin >> beltPos;

    if (beltPos < 1 || beltPos > 5) {
        cout << "posicao invalida!";
        return;
    }

    Item *item = maphero->removeItemFromBelt(beltPos);
    if (item != nullptr) {
        delete item;
        item = nullptr;
    }
}

void handleBackpack(Hero *hero) {
    Item *item = hero->getItemFromBackpack();
    if (item == nullptr) {
        return;
    }
    int choice;
    cout << "voce deseja: \n";
    cout << "1: utilizar o item (se for arma, deletara a arma equipada)\n";
    cout << "2: mover para o cinto\n";
    cout << "3: descartar: ";

    choice = makeChoice();

    Weapon *weapon = dynamic_cast<Weapon *>(item);
    Potion *potion = dynamic_cast<Potion *>(item);

    if (choice == 1) {
        if (potion) {
            double healingPower = potion->getHealingPower();
            hero->heal(healingPower);
        }

        if (weapon) {
            Weapon *newWeapon = new Weapon(*weapon);

            Weapon *equipedWeapon = hero->getWeapon();
            delete equipedWeapon;

            hero->equipWeapon(newWeapon);
        }

        hero->removeItemFromBackpack();
    }

    if (choice == 2) {
        if (weapon) {
            handleBeltStorage(weapon, hero);
        }

        if (potion) {
            handleBeltStorage(potion, hero);
        }
    }

    if (choice == 3) {
        delete item;
    }
}

bool isValidChoice(int choice) {
    return (choice < 1 || choice > 6);
}

int makeChoice() {
    int choice;

    while (true) {
        cout << "O que voce ira fazer?: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida! Por favor, insira um numero." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

void sleep(int secs) {
    sleep_for(seconds(secs));
}

struct Score {
        string name;
        int level;
        double pontuation;

        Score() : name(""), level(0), pontuation(0.0) {}

        Score(string n, int l, double p) : name(n), level(l), pontuation(p) {}

        bool isHigher(const Score &comparsion) {
            return pontuation > comparsion.pontuation;
        }
};
