#include <iostream>
#include "../include/animal.h"
#include "../include/cat.h"
#include "../include/dog.h"
#include "../include/cow.h"
#include "../include/sheep.h"
#include "../include/snake.h"

int main()
{
    // const int numAnimals = 5;
    // Animal* animals[numAnimals];

    // animals[0] = new Dog(150);
    // animals[1] = new Cat(80);
    // animals[2] = new Cow(600);
    // animals[3] = new Sheep(120);
    // animals[4] = new Snake(10);

    // for (int i = 0; i < numAnimals; ++i)
    // {
    //     animals[i]->stats();
    // }

    // std::cout << std::endl;

    // Comparison
    std::cout << "[COMPARISON OPERATOR]" << std::endl;
    
    Dog dog1(150);
    Dog dog2(100);
    
    if (dog1 < dog2)
    {
        std::cout << "dog 1 is lighter than dog 2" << std::endl;
    }

    if (dog1 > dog2)
    {
        std::cout << "dog 1 is heavier than dog 2" << std::endl;
    }

    if (dog1 == dog2)
    {
        std::cout << "dog 1 and dog 2 have the same weight" << std::endl;
    }else
    {
        std::cout << "dog1 and dog2 have different weights" << std::endl;
    }

    // for (int i = 0; i < numAnimals; ++i)
    // {
    //     delete animals[i];
    // }

    std::cout << "Press Enter to Close" << std::endl;
    std::cin.get();
    return 0;
}
