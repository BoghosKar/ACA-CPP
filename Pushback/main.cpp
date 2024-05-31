#include "../Pushback/vector.h"
#include <iostream>

int main()
{
    Vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Vector elements: [ ";
    for(int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    vec.pop_back();
    vec.pop_back();    

    std::cout << "Vector elements after popback: [ ";
    for(int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;
    
    
    vec.push_front(20);
    vec.push_front(30);

    std::cout << "Vector elements after push front: [ ";
    for(int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;

    vec.pop_front();
    vec.pop_front();    

    std::cout << "Vector elements after popfront: [ ";
    for(int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    vec.insert(1, 20);

    std::cout << "Vector elements after insert at 1: [ ";
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;

    std::cout << "Click Enter to close" << std::endl;
    std::cin.get();
    return 0;
}