#include <iostream>


class carRadio
{
private:
    std::string song1;
    std::string song2;
    std::string song3;

public:

    carRadio(const std::string& s1, const std::string& s2, const std::string& s3)
    {
        std::cout << "Call Parameter Constructor for carRadio" << std::endl;
        song1 = s1;
        song2 = s2;
        song3 = s3;
    }

    carRadio() {}

    ~carRadio()
    {
        std::cout << "Destructor for Radio" << std::endl;
    }

    void printRadio() const
    {
        std::cout << "song 1 = " << song1 << ", song 2 = " << song2 << ", song 3 = " << song3 << std::endl;
    }
};

class Car
{
private:
    std::string brand;
    std::string model;
    int year;
    int horsePower;
    carRadio radio;

public:

    Car(const std::string& b, const std::string& m, const int& y, const int& hp, const carRadio& r)
    : brand(b), model(m), year(y), horsePower(hp), radio(r)
    {
        std::cout << "Call Parameter Constructor for Car" << std::endl;
    }

    Car() {}

    ~Car()
    {
        std::cout << "Destructor for Car" << std::endl;
    }

    void Print() const
    {
        std::cout << "brand = " << brand << ", model = " << model << ", year = " << year << ", horse power = " << horsePower << std::endl;
    }

    void printRadio() const
    {
        radio.printRadio();
    }
};

class Parking
{
private:
    Car car;
    int size;
    int parkedCars;

public:

    Parking(int s)
    {
        size = s;
        parkedCars = 0;
    }

    Parking() {}

    ~Parking() 
    {
        std::cout << "Destructor for Parking" << std::endl;
    }

    void parkCar(const Car& c)
    {
        if (parkedCars < size)
        {
            car = c;
            parkedCars++;
            c.Print();
        } else
        {
            std::cout << "Parking is full" << std::endl;
        }
    }
};

int main()
{
    Car car1("Lada", "Niva", 1976, 76, carRadio("Tatul Avoyan - Srti Banali", "Tatul Avoyan - Garun e vardi buyrov", "Tigran Asatryan - Sirem Sirem"));
    Car car2("Lada", "Samara", 1998, 48, carRadio("Tatul Avoyan - Srti Banali", "Tatul Avoyan - Garun e vardi buyrov", "Tigran Asatryan - Sirem Sirem"));

    std::cout <<  std::endl << "Car models:" << std::endl;
    car1.Print();
    car2.Print();

    std::cout <<  std::endl << "Parking cars now" << std::endl;

    Parking parking(2);
    parking.parkCar(car1);
    parking.parkCar(car2);

    std::cout <<  std::endl << "Radio of parked cars:" << std::endl;
    car1.printRadio();
    car2.printRadio();
    std::cout << std::endl;

    return 0;
}
