#ifndef BUS_H
#define BUS_H

#include "../include/vehicle.h"

class Bus : public Vehicle
{
public:
    Bus();
    void vehicle() const override;
    ~Bus() override;
};

#endif // BUS_H