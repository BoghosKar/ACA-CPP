#include "../include/animal.h"

Animal::Animal(int weight) : weight(weight) {}

// copy
Animal::Animal(const Animal& other) : weight(other.weight) {}

// copy assignment
Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        weight = other.weight;
    }
    return *this;
}

// move
Animal::Animal(Animal&& other) noexcept : weight(other.weight)
{
    other.weight = 0;
}

// move assignment
Animal& Animal::operator=(Animal&& other) noexcept
{
    if (this != &other)
    {
        weight = other.weight;
        other.weight = 0;
    }
    return *this;
}

// comparison operators
bool Animal::operator < (const Animal& other) const
{
    return weight < other.weight;
}

bool Animal::operator > (const Animal& other) const
{
    return weight > other.weight;
}

bool Animal::operator == (const Animal& other) const
{
    return weight == other.weight;
}

// Destructor
Animal::~Animal() {}
