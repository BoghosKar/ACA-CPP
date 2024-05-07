#include "../include/creature.h"
#include <iostream>

Creature::Creature(int hp, int power) : hp(hp), power(power) {}

void Creature::getStats() {
    std::cout << "[HP]: " << hp << " [POWER]: " << power << std::endl;
}

Creature::~Creature() {}
