#include <iostream>

class Functor
{
public:

    void operator() () const 
    {
        std::cout << "Hello I am functor" << std::endl;
    }
};

int main()
{
    Functor functor;
    functor();

    return 0;
}