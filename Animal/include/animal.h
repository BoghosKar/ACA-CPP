#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
public:
    Animal(const std::string& voice, int age, int weight);
    virtual void stats() const = 0;
    virtual ~Animal();

protected:
    std::string voice;
    int age;
    int weight;
};

#endif // ANIMAL_H