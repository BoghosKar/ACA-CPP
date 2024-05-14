#include <iostream>

class Definition
{
private:
    int value;

public:
    Definition(int val) : value(val) {}

    Definition& operator ++ ()
    {
        ++value;
        return *this;
    }

    Definition operator ++ (int)
    {
        Definition temp(value);
        value++;
        return temp;
    }

    int getValue() const
    {
        return value;
    }
};
    

int main()
{
    Definition obj(10);

    std::cout << "[PREFIX BEFORE] : " << obj.getValue() << std::endl;
    ++obj;
    std::cout << "[PREFIX AFTER] : " << obj.getValue() << std::endl;

    std::cout << "[POSTFIX BEFORE]: " << obj.getValue() << std::endl;
    Definition obj2 = obj++;
    std::cout << "[POSTFIX AFTER]: " << obj.getValue() << std::endl;
    
    return 0;
}