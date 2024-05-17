#include "../include/animal.h"

Animal::Animal(const std::string& voice, int age, int weight) : voice(voice), age(age), weight(weight) {}

// copy 
Animal::Animal(const Animal& other) : voice(other.voice), age(other.age), weight(other.weight) {}


// copy assignment
Animal& Animal:: operator= (const Animal& other)
{
    if (this != &other)
    {
        voice = other.voice;
        age = other.age;
        weight = other.weight;
    }
    return *this;
}


// move
Animal::Animal(Animal&& other) : voice(std::move(other.voice)), age(other.age), weight(other.weight)
{
    other.age = 0;
    other.weight = 0;
}

// move assignment
Animal& Animal::operator = (Animal&& other)
{
    if (this != &other)
    {
        voice = std::move(other.voice);
        age = other.age;
        weight = other.weight;
        other.age = 0;
        other.weight = 0;
    }
    return *this;
}

Animal::~Animal() {}
