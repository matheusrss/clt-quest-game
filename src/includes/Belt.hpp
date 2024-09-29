#ifndef BELT_HPP
#define BELT_HPP

#include "Item.hpp"

class Belt {
    private:
        struct Node {
                Item *item;
                Node *next;
        };

        Node *head;
        double maxWeightPerSlot;
        int slotCount;

    public:
        Belt(double maxWeightPerSlot);

        bool addItemToSlot(Item *item, int slot);
        Item *removeItemFromSlot(int slot);

        Item *getItemFromSlot(int slot) const;
        double getMaxWeightPerSlot() const;

        ~Belt();
};

#endif
