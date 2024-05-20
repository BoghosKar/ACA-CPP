#include "../include/cow.h"

Cow::Cow(int weight) : Animal(weight) {}

void Cow::stats() const
{
    std::cout << "Weight: " << weight << std::endl;
}

Cow::~Cow(){}