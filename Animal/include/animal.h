#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
public:
    Animal(const std::string& voice, int age, int weight);
    
    Animal(const Animal& other); // copy
    Animal& operator = (const Animal& other); // copy assignment
    
    Animal(Animal&& other); // move 
    Animal& operator = (Animal&& other); // move assignment
    
    virtual void stats() const = 0;
    virtual ~Animal();

protected:
    std::string voice;
    int age;
    int weight;
};

#endif // ANIMAL_H
