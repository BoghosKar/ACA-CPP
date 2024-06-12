#ifndef DELETEBELOWAVERAGE_H
#define DELETEBELOWAVERAGE_H

#include <list>
#include "calculateAverage.h"

void deleteBelowAverage(std::list<int>& lst)
{
    double average = calculateAverage(lst);

    for(auto it = lst.begin(); it != lst.end();)
    {
        if(*it < average)
        {
            it = lst.erase(it);
        }else 
        {
            ++it;
        }
    }
}

#endif //DELETEBELOWAVERAGE_H