#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle
{
public:
    Vehicle() {}
    virtual void vehicle() const = 0;
    virtual ~Vehicle();
};

#endif // VEHICLE_H