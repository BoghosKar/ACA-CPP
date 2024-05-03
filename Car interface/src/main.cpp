#include <iostream>
#include "../include/vehicle.h"
#include "../include/sedan.h"
#include "../include/bus.h"
#include "../include/excavator.h"

int main()
{
    Vehicle* sedan = new Sedan();
    Vehicle* bus = new Bus();
    Vehicle* excavator = new Excavator();

    const int numVehicles = 3;
    Vehicle* vehicles[numVehicles] = {sedan, bus, excavator};

    for (int i = 0; i < numVehicles; i++)
    {
        vehicles[i]->vehicle();
    }

    for (int i = 0; i < numVehicles; i++)
    {
        delete vehicles[i];
    }

    std::cout << "Press Enter to close" << std::endl;
    std::cin.get();
    return 0;
}
