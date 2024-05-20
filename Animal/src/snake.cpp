#include "../include/snake.h"

Snake::Snake(int weight) : Animal(weight) {}

void Snake::stats() const
{
    std::cout << "Weight: " << weight << std::endl;
}

Snake::~Snake() {}
