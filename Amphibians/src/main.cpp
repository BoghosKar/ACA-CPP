#include <iostream>
#include "../include/water.h"
#include "../include/land.h"
#include "../include/frog.h"

int main()
{
    Frog frog;

    std::cout << "Frog stats: ";
    frog.getStats();

    std::cout << "Click Enter to close" << std::endl;
    std::cin.get();

    return 0;
}
