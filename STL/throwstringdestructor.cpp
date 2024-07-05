#include <iostream>
#include <exception>

class A
{
public:
    ~A()
    {
        try
        {
            throw std::string("Exception from destructor");
        } catch(const std::string& e)
        {
            std::cout << "Caught exception inside destructor: " << e << std::endl;
        }
    }
};

void createAndDestroyA()
{
    A a;
}

int main()
{
    try
    {
        createAndDestroyA();
    }catch (const std::string& e)
    {
        std::cout << "Caught an exception in main: " << e << std::endl;
    }

    return 0;
}