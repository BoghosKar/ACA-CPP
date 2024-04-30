#ifndef KING_H
#define KING_H

#include <iostream>
#include <string>

class King : public Pieces
{
public:
    King() {}

    void stats() const override
    {
        std::cout << "King, White" << std::endl;
    }
    
    virtual ~King() {}

};

#endif // KING_H