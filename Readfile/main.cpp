#include <iostream>
#include <fstream>

bool isInteger(const std::string& str)
{
    if (str.empty()) return false;
    
    size_t start;
    if (str[0] == '-')
    {
        start = 1;
    }else
    {
        start = 0;
    }
    
    for (size_t i = start; i < str.length(); ++i)
    {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

bool isFloat(const std::string& str)
{
    if (str.empty()) return false;
    
    size_t start;
    if (str[0] == '-')
    {
        start = 1;
    }else
    {
        start = 0;
    }

    bool decimalPointSeen = false;

    for (size_t i = start; i < str.length(); ++i)
    {
        if (str[i] == ',' || str[i] == '.')
        { 
            if (decimalPointSeen){ return false; }
            decimalPointSeen = true;
        } else if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return decimalPointSeen;
}

std::string determineType(const std::string& str)
{
    if (isInteger(str))
    {
        return "int";
    }else if (isFloat(str))
    {
        return "float";
    }else
    {
        return "string";
    }
}


int main()
{
    std::ifstream file("text.txt");
    
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::string type = determineType(line);
        std::cout << line << " - " << type << std::endl;
    }

    file.close();
    std::cout << "Click Enter to close" << std::endl;
    std::cin.get();
    return 0;
}