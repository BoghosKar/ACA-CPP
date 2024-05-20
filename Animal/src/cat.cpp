#include "../include/cat.h"

Cat::Cat(int weight) : Animal(weight) {}

void Cat::stats() const
{
    std::cout << "Weight: " << weight << std::endl;
}

Cat::~Cat() {}