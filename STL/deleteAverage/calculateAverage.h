#ifndef CALCULATEAVERAGE_H
#define CALCULATEAVERAGE_H

#include <list>

double calculateAverage(const std::list<int>& lst)
{
    double sum = 0;
    for(int num : lst)
    {
        sum += num;
    }
    return sum / lst.size();
}

#endif // CALCULATEAVERAGE_H