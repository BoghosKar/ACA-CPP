#include <iostream>

template <typename T>
class SmartPointer
{
private:
    T* ptr;

public:
    explicit SmartPointer(T* p = nullptr) : ptr(p) {}

    ~SmartPointer()
    {
        delete ptr;
    }

    T& operator * ()
    {
        return *ptr;
    }

    T* operator -> ()
    {
        return ptr;
    }

    SmartPointer(const SmartPointer&) = delete;
    SmartPointer operator = (const SmartPointer&) = delete;

    //move
    SmartPointer(SmartPointer&& other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }

    //move assignment
    SmartPointer& operator = (SmartPointer&& other) noexcept
    {
        if(this != &other)
        {
            delete other.ptr;
            other.ptr = ptr;
            ptr = nullptr;
        }
        return *this;
    }
};


class Test
{
public:
    void hello() const
    {
        std::cout << "Hello from Test" << std::endl;
    }
};


int main()
{
    SmartPointer<Test> sp(new Test());

    //access
    sp->hello();

    //derefeerence
    (*sp).hello();

    return 0;
}