#ifndef PIECES_H
#define PIECES_H

#include <iostream>
#include <string>

class Pieces
{
public:

    Pieces() {}

    virtual void stats() const
    {
        std::cout << "stats" << std::endl;
    }
    
    virtual ~Pieces() {}

};

#endif // PIECES_H