#include "../include/cow.h"

Cow::Cow(const std::string& voice, int age, int weight) : Animal(voice, age, weight) {}

void Cow::stats() const
{
    std::cout << "Cow says: " << voice << ", Age: " << age << ", Weight: " << weight << std::endl;
}

Cow::~Cow()
{
    // std::cout << __func__ << std::endl;
}