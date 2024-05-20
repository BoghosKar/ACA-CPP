#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
public:

    explicit Animal(int weight); // constructor

    Animal(const Animal& other); // copy
    Animal& operator = (const Animal& other); // copy assignment

    Animal(Animal&& other) noexcept; // move
    Animal& operator = (Animal&& other) noexcept; // move assignment

    bool operator < (const Animal& other) const; // < operator
    bool operator > (const Animal& other) const; // > operator
    bool operator == (const Animal& other) const; // == operator

    virtual void stats() const = 0;
    virtual ~Animal();

protected:
    int weight;
};

#endif // ANIMAL_H
