#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

using namespace std;

// Classe base Map, que define a interface para os diferentes tipos de mapas.
class Map {
public:
    virtual void trigger(int x, int y) = 0; // Função pura virtual para acionar eventos no mapa
    virtual void displayMap() const = 0;    // Exibe o mapa
    virtual ~Map() {}                       // Destrutor virtual para garantir limpeza adequada
};

// Classe derivada: VoidMap (mapa vazio)
class VoidMap : public Map {
public:
    void trigger(int x, int y) override;
    void displayMap() const override;
};

// Classe derivada: BattleMap (mapa de batalha)
class BattleMap : public Map {
public:
    void trigger(int x, int y) override;
    void displayMap() const override;
};

// Classe derivada: TreasureMap (mapa com Itens)
class TreasureMap : public Map {
public:
    void trigger(int x, int y) override;
    void displayMap() const override;
};

#endif 
