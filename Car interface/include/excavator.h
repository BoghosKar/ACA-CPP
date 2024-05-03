#ifndef EXCAVATOR_H
#define EXCAVATOR_H

#include "../include/vehicle.h"

class Excavator : public Vehicle
{
public:
    Excavator();
    void vehicle() const override;
    ~Excavator() override;
};

#endif // EXCAVATOR_H
