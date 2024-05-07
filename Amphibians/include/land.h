#ifndef LAND_H
#define LAND_H

#include <string>

class Land
{
protected:
    std::string land;

public:
    Land();
    Land(std::string land);
    void getStats();

    ~Land();
};

#endif // LAND_H