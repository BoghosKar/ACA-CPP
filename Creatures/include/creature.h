#ifndef CREATURE_H
#define CREATURE_H

class Creature
{
protected:
    int hp;
    int power;

public:
    Creature(int hp, int power);
    void getStats();

    ~Creature();
};

#endif // CREATURE_H
