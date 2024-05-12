#include "../zoosingleton/zoo.h"
#include <iostream>
#include "zoo.h"

Zoo& Zoo::getInstance()
{
    static Zoo instance;
    return instance;
}

void Zoo::setAnimal(Animal* newAnimal)
{
    animal = newAnimal;
}

void Zoo::displayAnimal() const
{
    animal->display();
    
}

Zoo::~Zoo() {}

Zoo::Zoo() {}
