#include <iostream>

template <typename T>
class ControlBlock
{
public:
    T* ptr;
    int ref_count;

    ControlBlock(T* p) : ptr(p), ref_count(1){}

    ~ControlBlock()
    {
        delete ptr;
    }
};