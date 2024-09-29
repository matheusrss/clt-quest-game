#ifndef MAPINTERFACE_HPP
#define MAPINTERFACE_HPP

#include "Hero.hpp"

class MapInterface {
    protected:
        Hero *hero;

    public:
        MapInterface(Hero *h) : hero(h) {}

        virtual void trigger(void *obj = nullptr) = 0;
        virtual void displayMap(void *obj = nullptr) const = 0;

        virtual ~MapInterface() {}

        Hero *getHero() const { return hero; }
};

#endif
