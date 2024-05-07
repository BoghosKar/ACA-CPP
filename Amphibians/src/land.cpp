#include "../include/land.h"
#include <iostream>

Land::Land() : land("I live on land") {}
Land::Land(std::string land) : land(land) {}

void Land::getStats()
{
    std::cout << land << std::endl;
}

Land::~Land() {}
