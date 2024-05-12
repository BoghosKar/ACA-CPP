#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
public:
    virtual void display() const = 0; 
    virtual ~Animal() {} 
};

#endif // ANIMAL_H
