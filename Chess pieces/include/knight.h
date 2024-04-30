#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include <string>

class Knight : public Pieces
{
public:
    Knight() {}

    void stats() const override
    {
        std::cout << "Knight, White" << std::endl;
    }
    
    virtual ~Knight() {}

};

#endif // KNIGHT_H