#include <iostream>
#include <vector>
#include <algorithm>

bool is_prime(int n)
{
    if(n <= 1)
    {
        return false;
    }

    for(int i = 2; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::vector<int> vec = {2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Vector before removing primes: ";

    for(int num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    vec.erase(std::remove_if(vec.begin(), vec.end(), is_prime), vec.end());

    std::cout << "Vector after removing primes: ";

    for(int num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}