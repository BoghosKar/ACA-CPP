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

enum valueType
{
    INT,
    FLOAT,
    STRING
};

valueType determineType(const std::string& str)
{
    if (isInteger(str))
    {
        return INT;
    }else if (isFloat(str))
    {
        return FLOAT;
    }else
    {
        return STRING;
    }
}


int main()
{
    std::ifstream file("text.txt");
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line))
    {
        valueType type = determineType(line);
        std::cout << line << " - ";
        
        switch (type) {
            case INT:
            {
                std::cout << "int";
                break;
            }
            case FLOAT:
            {
                std::cout << "float";
                break;
            }
            case STRING:
            {
                std::cout << "string";
                break;
            }
            default:
            {
                std::cout << "unknown";
                break;
            }
        }
        std::cout << std::endl;
    }

    file.close();
    std::cout << "Press Enter to Close" << std::endl;
    std::cin.get();
    return 0;
}