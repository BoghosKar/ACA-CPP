#ifndef STACKUSINGLIST_H
#define STACKUSINGLIST_H

#include "CustomForwardList.h"

class StackUsingList : private ForwardList
{
public:
    using ForwardList::push_front;
    using ForwardList::pop_front;
    using ForwardList::front;
    using ForwardList::empty;
};

#endif // STACKUSINGLIST_H