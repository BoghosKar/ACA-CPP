#ifndef PULT_H
#define PULT_H

#include <iostream>

class Pult
{
public:
    Pult() {}
    virtual void pult() const = 0;
    virtual ~Pult();
};

#endif // PULT_H