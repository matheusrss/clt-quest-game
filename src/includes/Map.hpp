#ifndef MAP_HPP
#define MAP_HPP

#include "MapInterface.hpp"
#include "Enemy.hpp"
#include "Weapon.hpp"
#include <iostream>

using namespace std;

// Classe template para Map com tipo genérico T
template <typename T>
class Map : public MapInterface {
public:
    Map(Hero* h) : MapInterface(h) {}

    // Sobrescreve métodos virtuais e aceita objetos de tipo T
    void trigger(void* obj) override;
    void displayMap(void* obj) const override;

    ~Map() {}
};

// Especializacão de Map<void> (caso vazio)
template <>
class Map<void> : public MapInterface {
public:
    Map(Hero* h) : MapInterface(h) {}

    // Sobrescreve métodos virtuais para a especializacão void (sem parâmetros)
    void trigger(void* = nullptr) override;
    void displayMap(void* = nullptr) const override;

    ~Map<void>() {}
};

#endif  // MAP_HPP
