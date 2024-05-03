#ifndef SEDAN_H
#define SEDAN_H

#include "vehicle.h"

class Sedan : public Vehicle
{
public:
    Sedan();
    void vehicle() const override;
    ~Sedan() override;
};

#endif // SEDAN_H
