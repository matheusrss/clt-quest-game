#include <string>

using namespace std;

#ifndef ITEM_HPP
#define ITEM_HPP

class Item {
    protected:
        string name;
        double weight;
        string prefix;
        string suffix;
        string type;

    public:
        virtual ~Item() = 0;

        virtual string getName() const = 0;
        virtual double getWeight() const = 0;
        virtual string getPrefix() const = 0;
        virtual string getSuffix() const = 0;
        virtual string getType() const = 0;

};

#endif