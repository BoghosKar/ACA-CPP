#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
public:
    std::string make;
    std::string model;
    int year;

    Car(const std::string& make, const std::string& model, int year) : make(make), model(model), year(year) {}

    bool operator == (const Car& other) const
    {
        return make == other.make && model == other.model && year == other.year;
    }
};

#endif //CAR_H