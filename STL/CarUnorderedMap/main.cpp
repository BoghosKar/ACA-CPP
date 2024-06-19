#include <iostream>
#include <unordered_map>
#include "car.h"
#include "carhash.h"

int main()
{
    std::unordered_map<Car, std::string, CarHash> carMap;

    Car car1("Toyota", "Camry", 2020);
    Car car2("Honda", "Accord", 2018);
    Car car3("Ford", "Mustang", 2022);

    carMap[car1] = "Sedan";
    carMap[car2] = "Sedan";
    carMap[car3] = "Coupe";

    for(const auto& entry : carMap)
    {
        std::cout << entry.first.make << " " << entry.first.model << " " << entry.first.year << " -> " << entry.second << std::endl;
    }


    std::cout << "Click Enter to close" << std::endl;
    return 0;
}