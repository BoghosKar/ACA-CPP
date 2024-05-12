#ifndef DOG_H
#define DOG_H

#include "../zoosingleton/animal.h"


class Dog : public Animal
{
public:
    void display() const override;
};

#endif // DOG_H
