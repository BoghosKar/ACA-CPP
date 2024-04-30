#ifndef SNAKE_H
#define SNAKE_H

#include "animal.h"

class Snake : public Animal
{
public:
    Snake(const std::string& voice, int age, int weight);
    void stats() const override;
    ~Snake() override;
};

#endif // SNAKE_H
