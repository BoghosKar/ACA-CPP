#ifndef WATER_H
#define WATER_H

#include <string>

class Water
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