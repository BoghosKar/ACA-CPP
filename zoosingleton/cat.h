#ifndef CAT_H
#define CAT_H

#include "../zoosingleton/animal.h"

class Cat : public Animal
{
public:
    void display() const override;
};

#endif // CAT_H
