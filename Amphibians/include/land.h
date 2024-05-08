#ifndef LAND_H
#define LAND_H

#include <string>
#include "../include/animal.h"

class Land : public virtual Animal
{
protected:
    std::string land;

public:
    Land();
    Land(std::string land);
    void getStats();

    ~Land();
};

#endif // LAND_H