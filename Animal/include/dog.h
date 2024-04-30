#ifndef DOG_H
#define DOG_H

#include "animal.h"

class Dog : public Animal
{
public:
    Dog(const std::string& voice, int age, int weight);
    void stats() const override;
    ~Dog() override;
};

#endif // DOG_H
