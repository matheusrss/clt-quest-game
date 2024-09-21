#include <string>

using namespace std;

#ifndef ITEM_HPP
#define ITEM_HPP

class Item {
    protected:
        string name;
        double weight;

    public:
        virtual ~Item() = 0;

        virtual string getName() const = 0;
        virtual double getWeight() const = 0;
};

void testing();

#endif