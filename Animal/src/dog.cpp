#include "../include/dog.h"

Dog::Dog(const std::string& voice, int age, int weight) : Animal(voice, age, weight) {}

void Dog::stats() const
{
    std::cout << "Dog says: " << voice << ", Age: " << age << ", Weight: " << weight << std::endl;
}

Dog::~Dog()
{
    // std::cout << __func__ << std::endl;
}