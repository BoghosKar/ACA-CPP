#ifndef VOLDOWN_H
#define VOLDOWN_H

#include "../include/pult.h"

class Voldown : public Pult
{
public:
    Voldown();
    void pult() const override;
    ~Voldown() override;
};

#endif // VOLDOWN_H
