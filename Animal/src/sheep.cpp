#include "../include/sheep.h"

Sheep::Sheep(int weight) : Animal(weight) {}

void Sheep::stats() const
{
    std::cout << "Weight: " << weight << std::endl;
}

Sheep::~Sheep() {}
