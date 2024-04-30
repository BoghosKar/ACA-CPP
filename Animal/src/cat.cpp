#include "../include/cat.h"

Cat::Cat(const std::string& voice, int age, int weight) : Animal(voice, age, weight) {}

void Cat::stats() const
{
    std::cout << "Cat says: " << voice << ", Age: " << age << ", Weight: " << weight << std::endl;
}

Cat::~Cat()
{
    // std::cout << __func__ << std::endl;
}