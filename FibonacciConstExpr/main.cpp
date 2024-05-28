#include <iostream>
#include "../FibonacciConstExpr/fibonacci.h"

int main()
{
    constexpr int fib_0 = fibonacci(0);
    constexpr int fib_1 = fibonacci(1);
    constexpr int fib_5 = fibonacci(5);
    constexpr int fib_10 = fibonacci(10);
    constexpr int fib_20 = fibonacci(20);

    std::cout << "[FIBONACCI 0]: " << fib_0 << std::endl;
    std::cout << "[FIBONACCI 1]: " << fib_1 << std::endl;
    std::cout << "[FIBONACCI 5]: " << fib_5 << std::endl;
    std::cout << "[FIBONACCI 10]: " << fib_10 << std::endl;
    std::cout << "[FIBONACCI 20]: " << fib_20 << std::endl;


    std::cout << std::endl << "Click Enter to close" << std::endl;
    std::cin.get();
    return 0;
}
