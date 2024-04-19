#include <iostream>

class Car {
public:
    std::string brand;
    std::string model;
    int year;
    int speed;
    int horsePower;

    void PrintInfo() {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Speed: " << speed << " km/h" << std::endl;
        std::cout << "Horsepower: " << horsePower << " hp" << std::endl;
    }
};

int main() {
    Car myCar;
    myCar.brand = "Ferrari";
    myCar.model = "812 superfast";
    myCar.year = 2017;
    myCar.speed = 340 ;
    myCar.horsePower = 789;

    myCar.PrintInfo();

    return 0;
}
