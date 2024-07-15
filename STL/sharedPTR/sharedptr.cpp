#include <iostream>
#include "controlblock.cpp"

template <typename T>
class SharedPointer
{
private:
    ControlBlock<T>* control_block;

public:
    explicit SharedPointer(T* ptr = nullptr) : control_block(nullptr)
    {
        if(ptr)
        {
            control_block = new ControlBlock<T>(ptr);
        }
    }

    //copy
    SharedPointer(const SharedPointer& other)
    {
        control_block = other.control_block;
        if(control_block)
        {
            control_block->ref_count++;
        }
    }

    //move
    SharedPointer(SharedPointer&& other) noexcept
    {
        control_block = other.control_block;
        other.control_block = nullptr;
    }

    //copy =
    SharedPointer& operator = (const SharedPointer& other)
    {
        if(this != &other)
        {
            if(control_block && --control_block->ref_count == 0)
            {
                delete control_block;
            }

            control_block = other.control_block;
            if(control_block)
            {
                control_block->ref_count++;
            }
        }

        return *this;
    }


    //move =
    SharedPointer& operator = (SharedPointer&& other)
    {
        if (this != &other)
        {
            if (control_block && --control_block->ref_count == 0)
            {
                delete control_block;
            }

            control_block = other.control_block;
            other.control_block = nullptr;
        }
        return *this;
    }

    ~SharedPointer()
    {
        if(control_block && --control_block->ref_count == 0)
        {
            delete control_block;
        }
    }

    T& operator * () const
    {
        return *(control_block->ptr);
    }

    T& operator -> () const
    {
        return control_block->ptr;
    }
    
    int use_count() const
    {
        if(control_block)
        {
            return control_block->ref_count;
        }else
        {
            return 0;
        }
    }
};

int main()
{
    SharedPointer<int> sp1(new int(10));
    std::cout << "Shared ptr 1 use_count: " << sp1.use_count() << std::endl;

    {
        SharedPointer<int> sp2 = sp1;
        std::cout << "Shared ptr 1 use_count: " << sp1.use_count() << std::endl;
        std::cout << "Shared ptr 2 use_count: " << sp2.use_count() << std::endl;
    }
    std::cout << "Shared ptr 1 use_count: " << sp1.use_count() << std::endl;

    return 0;
}