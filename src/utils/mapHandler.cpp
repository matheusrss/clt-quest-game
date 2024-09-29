#include "Utils.hpp"
#include <iostream>

void handleEnemyMap(Enemy *enemy, Hero *maphero) {
    int choice;

    do {
        // Exibe o status antes do turno
        displayInterface("Inicio do turno", maphero, "enemy", enemy);
        choice = makeChoice();

        // Checa se a escolha é valida
        if (isValidChoice(choice)) {
            cout << "Comando invalido!!! Refazer escolha.\n";
            continue;
        }

        // Acao do jogador
        if (choice == 1) {
            maphero->attack(enemy);
            cout << enemy->getName() << " recebeu dano. HP atual: " << enemy->getCurrentHealth() << "/" << enemy->getMaxHealth() << "\n";

            // Verifica se o inimigo foi derrotado
            if (!enemy->isAlive()) {
                cout << enemy->getName() << " foi derrotado!\n";
                break;
            }
        }

        if (choice == 2) {
            cout << maphero->getName() << " esta verificando sua mochila.\n";
            handleBackpack(maphero);
        }

        if (choice == 3) {
            cout << maphero->getName() << " esta utilizando um item do cinto.\n";
            handleBeltUsage(maphero);
        }

        // Contra-ataque do inimigo, se ele ainda estiver vivo
        if (enemy->isAlive()) {
            cout << enemy->getName() << " contra-ataca " << maphero->getName() << "!\n";
            enemy->attack(maphero);

            if (!maphero->isAlive()) {
                cout << maphero->getName() << " foi derrotado pelo " << enemy->getName() << "!\n";
                break;
            } else {
                cout << maphero->getName() << " recebeu dano. HP atual: " << maphero->getCurrentHealth() << "/" << maphero->getMaxHealth() << "\n";
            }
        }
        // Exibe o status atualizado após o turno
        displayInterface("Fim do turno", maphero, "enemy", enemy);

    } while (true);

    // Mensagem final
    string message = enemy->isAlive() ? "Voce morreu!!!" : "Voce derrotou seu inimigo!!! Espere o proximo turno!";
    displayInterface(message, maphero, "enemy", enemy);

    delete enemy;
}

void handleItemMap(Weapon *weapon, Hero *maphero) {
    int choice;

    do {
        choice = makeChoice();

        if (isValidChoice(choice)) {
            cout << "Comando invalido!!!\n";
            continue;
        }

        if (choice == 1) {
            if (!weapon) {
                cout << "Voce ja pegou a arma, ou nao, nunca saberemos\n";
                continue;
            }

            handleWeaponStorage(weapon, maphero);
            delete weapon;
            weapon = nullptr;
        }

        if (choice == 2) {
            if (weapon) {
                delete weapon;
                weapon = nullptr;
            }
            choice = 5;
        }

        if (choice == 3) {
            handleBeltUsage(maphero);
        }

        if (choice == 4) {
            handleBackpack(maphero);
        }

        if(choice == 5) {
            handleBeltDelete(maphero);
        }

    } while (choice != 6);
    if (weapon != nullptr) {
        delete weapon;
        weapon = nullptr;
    }
}

void handleItemMap(Potion *potion, Hero *maphero) {
    int choice;

    do {
        choice = makeChoice();

        if (isValidChoice(choice)) {
            cout << "Comando invalido!!!\n";
            continue;
        }

        if (choice == 1) {
            if (!potion) {
                cout << "Voce ja pegou a pocao, ou nao, nunca saberemos\n";
                continue;
            }

            handlePotionStorage(potion, maphero);
            delete potion;
            potion = nullptr;
        }

        if (choice == 2) {
            if (potion) {
                delete potion;
                potion = nullptr;
            }
            choice = 5;
        }

        if (choice == 3) {
            handleBeltUsage(maphero);
        }

        if (choice == 4) {
            handleBackpack(maphero);
        }

        if(choice == 5) {
            handleBeltDelete(maphero);
        }

    } while (choice != 6);

    if (potion != nullptr) {
        delete potion;
        potion = nullptr;
    }
}

void handleVoidMap(Hero *maphero) {

    int choice;

    do {
        choice = makeChoice();

        if (choice == 1) {
            handleBackpack(maphero);
        }

        if (choice == 2) {
            handleBeltUsage(maphero);
        }

    } while (choice != 3);
}
