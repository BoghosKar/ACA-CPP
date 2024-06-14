#include <iostream>
#include <map>
#include <string>


int main()
{   
    std::map<int, std::string> map;
    
    map[1] = "one";
    map[2] = "two";
    map[3] = "three";
    map[4] = "four";
    map[5] = "five";
    map[6] = "six";
    map[7] = "seven";
    map[8] = "eight";
    map[9] = "nine";
    map[10] = "ten";

    std::map<int, std::string>::iterator it = map.begin();

    while(it != map.end())
    {
        std::cout << "[VALUE]; " << it->first << " [WORD]: " << it->second << std::endl;
        ++it;
    }

    return 0;
}