#ifndef FROG_H
#define FROG_H

#include "water.h"
#include "land.h"
#include "animal.h"

class Frog : public virtual Water, public virtual Land, public virtual Animal
{
public:
    Frog();

    void getStats();

    ~Frog();
};

#endif // FROG_H