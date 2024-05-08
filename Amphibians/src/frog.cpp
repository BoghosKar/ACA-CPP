#include "../include/frog.h"
#include <iostream>

Frog::Frog() {}

void Frog::getStats()
{
    std::cout << water << ", " << land << std::endl;
}

Frog::~Frog() {}