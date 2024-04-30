#ifndef SHEEP_H
#define SHEEP_H

#include "animal.h"

class Sheep : public Animal
{
public:
    Sheep(const std::string& voice, int age, int weight);
    void stats() const override;
    ~Sheep() override;
};

#endif // SHEEP_H
