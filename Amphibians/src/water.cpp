#include "../include/water.h"
#include <iostream>

Water::Water() : water("I live in the water") {}
Water::Water(std::string water) : water(water) {}

void Water::getStats()
{
    std::cout << water << std::endl;
}

Water::~Water() {}