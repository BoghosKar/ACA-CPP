#include "../include/snake.h"

Snake::Snake(const std::string& voice, int age, int weight) : Animal(voice, age, weight) {}

void Snake::stats() const
{
    std::cout << "Snake says: " << voice << ", Age: " << age << ", Weight: " << weight << std::endl;
}

Snake::~Snake()
{
    // std::cout << __func__ << std::endl;
}
