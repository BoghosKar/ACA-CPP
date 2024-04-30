#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include <string>

class Pawn : public Pieces
{
public:
    Pawn() {}

    void stats() const override
    {
        std::cout << "Pawn, White" << std::endl;
    }
    
    virtual ~Pawn() {}

};

#endif // PAWN_H