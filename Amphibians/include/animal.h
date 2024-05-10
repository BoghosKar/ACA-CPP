#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
private:
    static int count;
public:
    Animal();
    virtual ~Animal();
    static int getCount();
};

#endif // ANIMAL_H