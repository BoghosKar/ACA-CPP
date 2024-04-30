#include <iostream>
#include "../include/animal.h"
#include "../include/dog.h"
#include "../include/cat.h"
#include "../include/cow.h"
#include "../include/sheep.h"
#include "../include/snake.h"

int main()
{  
    const int numAnimals = 5;
    Animal* animals[numAnimals];

    animals[0] = new Dog("woof", 10, 150);
    animals[1] = new Cat("meow", 5, 80);
    animals[2] = new Cow("moo", 15, 600);
    animals[3] = new Sheep("baaa", 8, 120);
    animals[4] = new Snake("ssssssssss", 2, 10);
    
    for (int i = 0; i < numAnimals; ++i)
    {
        animals[i]->stats();
    }

    for (int i = 0; i < numAnimals; ++i)
    {
        delete animals[i];
    }

    std::cout << "Click Enter to close";
    std::cin.get();

    return 0;
}
