#ifndef PAUSE_H
#define PAUSE_H

#include "../include/pult.h"

class Pause : public Pult
{
public:
    Pause();
    void pult() const override;
    ~Pause() override;
};

#endif // PAUSE_H
