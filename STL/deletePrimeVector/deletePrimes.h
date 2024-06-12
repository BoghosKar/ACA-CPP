#ifndef DELETEPRIMES_H
#define DELETEPRIMES_H

#include <vector>
#include "isPrime.h"

void deletePrimes(std::vector<int>& vec)
{
    for(auto it =vec.begin(); it != vec.end();)
    {
        if(isPrime(*it))
        {
            it = vec.erase(it);
        }else
        {
            ++it;
        }
    }
}

#endif // DELETEPRIMES_H
