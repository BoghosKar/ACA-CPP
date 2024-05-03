#include "../include/bus.h"
#include <iostream>

Bus::Bus() {}

void Bus::vehicle() const
{
    std::cout << "I am a bus" << std::endl;
}

Bus::~Bus() {}