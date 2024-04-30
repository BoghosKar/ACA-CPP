#ifndef CAT_H
#define CAT_H

#include "animal.h"

class Cat : public Animal
{
public:
    Cat(const std::string& voice, int age, int weight);
    void stats() const override;
    ~Cat() override;
};

#endif // CAT_H
