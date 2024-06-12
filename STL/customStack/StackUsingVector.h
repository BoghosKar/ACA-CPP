#ifndef STACKUSINGVECTOR_H
#define STACKUSINGVECTOR_H

#include <vector>
#include <stdexcept>

class StackUsingVector : private std::vector<int>
{
public:
    using std::vector<int>::push_back;
    using std::vector<int>::pop_back;
    using std::vector<int>::back;
    using std::vector<int>::empty;
};

#endif // STACKUSINGVECTOR_H
