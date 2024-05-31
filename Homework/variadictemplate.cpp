#include <iostream>

void print()
{
    std::cout << std::endl;
}

template <typename T, typename... Args>
void print(T first, Args... args)
{
    std::cout << first << " ";
    print(args...);
}

int main()
{
    print(1, 1.5, "hello", "a");

    return 0;
}
