#include "../include/dog.h"

Dog::Dog(int weight) : Animal(weight) {}

void Dog::stats() const
{
    std::cout << "Dog Weight: " << weight << std::endl;
}

Dog::~Dog() {}