#include <iostream>

class Vehicle
{
public:
    std::string m_type;
    std::string m_motor;
    int m_wheels;
    std::string song1;
    std::string song2;
    std::string song3;


    Vehicle() {}

    Vehicle(const std::string t, const std::string m, const int w): m_type(t), m_motor(m), m_wheels(w) 
    {
        // std::cout << "Call Vehicle Constructor" << std::endl;
        std::cout << std::endl;
    }

    void PrintInfo()
    {
        std::cout << "[TYPE]: " << m_type << ", [MOTOR]: " << m_motor << ", [WHEELS]: " << m_wheels;
        std::cout << std::endl;
    }

    ~Vehicle() {}

 
    void PrintRadio()
    {
        std::cout << "song 1 = " << song1 << ", song 2 = " << song2 << ", song 3 = " << song3 << std::endl;
    }

};



///////////////////////// SEDAN //////////////////////// 

class Sedan : public Vehicle
{
public:
    Vehicle sedan;

    Sedan() {}

    Sedan(const std::string t, const std::string m, const int w) : Vehicle(t, m, w) {}
    
    ~Sedan() {}
};

class sedanRadio : public Sedan
{
public:
    Sedan sedan;

    sedanRadio() {}

    sedanRadio(const std::string& s1, const std::string& s2, const std::string& s3)
    {
        song1 = s1;
        song2 = s2;
        song3 = s3;
        PrintRadio();
    }

    
    ~sedanRadio() {}
};

/////////////////////////////////////////////////



//////////////////////// PICKUP /////////////////////////

class Pickup : public Vehicle
{
public:
    Vehicle pickup;

    Pickup() {}

    Pickup(const std::string t, const std::string m, const int w) : Vehicle(t, m, w) {}

    ~Pickup() {}
};

class pickupRadio : public Pickup
{
public:
    Pickup pickup;

    pickupRadio() {}

    pickupRadio(const std::string& s1, const std::string& s2, const std::string& s3)
    {
        song1 = s1;
        song2 = s2;
        song3 = s3;
        PrintRadio();
    }

    ~pickupRadio() {}
};

/////////////////////////////////////////////////


//////////////////// BULLDOZER /////////////////////////////

class BullDozer : public Vehicle
{
public:
    Vehicle bulldozer;

    BullDozer() {}

    BullDozer(const std::string t, const std::string m, const int w) : Vehicle(t, m, w) {}

    ~BullDozer() {}
};

class bulldozerRadio : public BullDozer
{
public:
    BullDozer bulldozer;

    bulldozerRadio() {}

    bulldozerRadio(const std::string& s1, const std::string& s2, const std::string& s3)
    {
        song1 = s1;
        song2 = s2;
        song3 = s3;
        PrintRadio();
    }

    ~bulldozerRadio() {}
};

/////////////////////////////////////////////////



int main()
{

    ///Sedan
    Sedan sedan("Toyota Camry", "Gas", 4);
    sedan.PrintInfo();
    sedanRadio sedanRadio("Charles Aznavour", "Komitas", "Aram Khachatryan");
    ///
    
    ///Pikcup
    Pickup pickup("Ford F-150", "Gas", 4);
    pickup.PrintInfo();
    pickupRadio pickupRadio("Charles Aznavour", "Komitas", "Aram Khachatryan");
    ///

    ///Bulldozer
    BullDozer bulldozer("Caterpillar", "Diesel", 2);
    bulldozer.PrintInfo();
    bulldozerRadio bulldozerRadio("Charles Aznavour", "Komitas", "Aram Khachatryan");
    ///

    std::cout << std::endl;

    return 0;
}