#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include <string>

class Queen : public Pieces
{
public:
    Queen() {}

    void stats() const override
    {
        std::cout << "Queen, White" << std::endl;
    }
    
    virtual ~Queen() {}

};

#endif // Queen_H