#ifndef SNAKE_H
#define SNAKE_H

#include "animal.h"

class Snake : public Animal
{
public:
    explicit Snake(int weight);
    void stats() const override;
    ~Snake() override;
};

#endif // SNAKE_H
