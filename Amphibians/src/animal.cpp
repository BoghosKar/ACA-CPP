#include "../include/animal.h"

int Animal::count = 0;

Animal::Animal()
{
    count++;
}

Animal::~Animal()
{
    count--;
}

int Animal::getCount()
{
    return count;
}