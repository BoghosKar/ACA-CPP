#ifndef CARHASH_H
#define CARHASH_H

#include "car.h"
#include <functional>

struct CarHash
{
    std::size_t operator () (const Car& car) const
    {
        return std::hash<std::string>()(car.make) ^ (std::hash<std::string>()(car.model) << 1) ^ (std::hash<int>()(car.year) << 2);
    }
};


#endif // CARHASH_H