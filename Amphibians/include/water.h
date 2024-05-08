#ifndef WATER_H
#define WATER_H

#include <string>
#include "../include/animal.h"

class Water : public virtual Animal
{
protected:
    std::string water;

public:
    Water();
    Water(std::string water);
    void getStats();

    ~Water();
};

#endif // WATER_H