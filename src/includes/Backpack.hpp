#ifndef BACKPACK_HPP
#define BACKPACK_HPP

#include "Item.hpp"

class Backpack {
    private:
        struct Node {
                Item *item;
                Node *next;
        };

        Node *top;

    public:
        Backpack();

        bool addItem(Item *item);

        Item *removeItem();

        Item *getLastItem() const;

        int getItemCount() const;

        ~Backpack();
};

#endif
