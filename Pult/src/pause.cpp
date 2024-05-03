#include "../include/pause.h"
#include <iostream>

Pause::Pause() {}

void Pause::pult() const
{
    std::cout << "I am the pause button" << std::endl;
}

Pause::~Pause() {}
