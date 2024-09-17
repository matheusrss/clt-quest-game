#ifndef GAME_HPP
#define GAME_HPP

#include "map.hpp" // Inclui o cabeçalho com as classes de mapa

using namespace std;

class Game {
private:
    Map* currentMap;   // Ponteiro para o mapa atual (pode ser VoidMap, BattleMap ou TreasureMap)
    int heroX, heroY;  // Coordenadas do herói no mapa

public:
    // Construtor da classe Game
    Game(Map* initialMap);

    // Função para alterar o mapa atual
    void changeMap(Map* newMap);

    // Função para mover o herói no mapa
    void moveHero(int x, int y);

    // Função para iniciar o jogo
    void start();

    // Função para exibir o mapa atual
    void displayCurrentMap() const;

    // Destrutor da classe Game
    ~Game();
};

#endif // GAME_HPP
