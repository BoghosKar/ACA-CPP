#include <iostream>
#include "../zoosingleton/zoo.h"
#include "../zoosingleton/cat.h"
#include "../zoosingleton/dog.h"


int main()
{
    Cat cat;
    Dog dog;

    Zoo::getInstance().setAnimal(&cat);
    Zoo::getInstance().displayAnimal();

    Zoo::getInstance().setAnimal(&dog);
    Zoo::getInstance().displayAnimal();

    std::cout << "Click Enter to close" << std::endl;
    std::cin.get();
    return 0;
}
