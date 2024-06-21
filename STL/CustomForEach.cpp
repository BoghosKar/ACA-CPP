#include <iostream>

template <typename InputIterator, typename Function>
Function for_each(InputIterator first, InputIterator last, Function func)
{
    for(; first != last; ++first)
    {
        func(*first);
    }
    return func;
}

void printElement(int x)
{
    std::cout << x << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    for_each(arr, arr + 5, printElement);

    std::cout << std::endl;

    return 0;
}