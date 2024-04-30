#include "../include/sheep.h"

Sheep::Sheep(const std::string& voice, int age, int weight) : Animal(voice, age, weight) {}

void Sheep::stats() const
{
    std::cout << "Sheep says: " << voice << ", Age: " << age << ", Weight: " << weight << std::endl;
}

Sheep::~Sheep()
{
    // std::cout << __func__ << std::endl;
}
