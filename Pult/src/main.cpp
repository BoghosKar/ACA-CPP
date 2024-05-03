#include <iostream>
#include "../include/pult.h"
#include "../include/pause.h"
#include "../include/volup.h"
#include "../include/voldown.h"

int main()
{
    Pult* btn1 = new Pause();
    Pult* btn2 = new Voldown();
    Pult* btn3 = new Volup();

    const int numButtons = 3;
    Pult* buttons[numButtons] = {btn1, btn2, btn3};

    for (int i = 0; i < numButtons; i++)
    {
        buttons[i]->pult();
    }

    for (int i = 0; i < numButtons; i++)
    {
        delete buttons[i];
    }

    std::cout << "Press Enter to close" << std::endl;
    std::cin.get();
    return 0;
}
