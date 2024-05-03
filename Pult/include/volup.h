#ifndef VOLUP_H
#define VOLUP_H

#include "../include/pult.h"

class Volup : public Pult
{
public:
    Volup();
    void pult() const override;
    ~Volup() override;
};

#endif // VOLUP_H