#include <iostream>
#include "../include/elf.h"
#include "../include/archer.h"
#include "../include/elfarcher.h"

int main() {
    Elf elf;
    Archer archer;
    ElfArcher elfArcher;

    std::cout << "Elf stats: ";
    elf.getStats();

    std::cout << "Archer stats: ";
    archer.getStats();

    std::cout << "ElfArcher stats: ";
    elfArcher.getStats();

    std::cout << "Click Enter to close" << std::endl;
    std::cin.get();
    
    return 0;
}
