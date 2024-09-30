#include "FileHandler.hpp"
#include "Game.hpp"
#include "Hero.hpp"
#include "Utils.hpp"
#include <iostream>

using namespace std;


/*
string nomes[3] = {"Luis Gustavo", "Matheus Ricardo", "Raul Emanoel"};
string codigos[3] = {"2211498", "2224100", "2225210"};
*/

int main() {
    string name;

    cout << "Informe seu nick: ";
    cin >> name;
    cout << endl;

    Hero *hero = new Hero(name, 250.0, 10.0);
    // Criacão do jogo com o herói
    int mode;

    cout << "Escolha o tema do jogo, 0(CLT), 1(RPG)\n";
    mode = makeChoice();
    while(mode != 0 && mode != 1) {
        cout << "comando invalido!!!\n";
        mode = makeChoice();
    }
    
    Game *game = new Game(hero, mode);

    // Início do jogo
    game->start();
    game->end();

    // Liberacão da memória alocada
    delete game;
    delete hero;

    return 0;
}
