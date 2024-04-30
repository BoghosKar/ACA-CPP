#ifndef ROOKS_H
#define ROOK_H

#include <iostream>
#include <string>

class Rook : public Pieces
{
public:
    Rook() {}

    void stats() const override
    {
        std::cout << "Rook, White" << std::endl;
    }
    
    virtual ~Rook() {}

};

#endif // ROOK_H