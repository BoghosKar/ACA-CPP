#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include <string>

class Bishop : public Pieces
{
public:
    Bishop() {}

    void stats() const override
    {
        std::cout << "Bishop, White" << std::endl;
    }
    
    virtual ~Bishop() {}

};

#endif // BISHOP_H