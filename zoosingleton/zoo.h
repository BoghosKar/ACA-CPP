#ifndef ZOO_H
#define ZOO_H

#include "../zoosingleton/animal.h"

class Zoo
{
public:
    static Zoo& getInstance();

    void setAnimal(Animal* newAnimal);

    void displayAnimal() const;

protected:
    Zoo();
    ~Zoo();
    Animal* animal; 
};

#endif // ZOO_H
