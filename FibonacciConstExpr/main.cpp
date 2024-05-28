#include <iostream>
#include "../FibonacciConstExpr/fibonacci.h"

int main()
{

    constexpr int fib_0 = Fibonacci<0>::value;
    constexpr int fib_1 = Fibonacci<1>::value;
    constexpr int fib_5 = Fibonacci<5>::value;
    constexpr int fib_10 = Fibonacci<10>::value;
    constexpr int fib_20 = Fibonacci<20>::value;

    std::cout << "Fibonacci(0): " << fib_0 << std::endl;
    std::cout << "Fibonacci(1): " << fib_1 << std::endl;
    std::cout << "Fibonacci(5): " << fib_5 << std::endl;
    std::cout << "Fibonacci(10): " << fib_10 << std::endl;
    std::cout << "Fibonacci(20): " << fib_20 << std::endl;

    std::cout << std::endl << "Click Enter to close" << std::endl;
    std::cin.get();
    return 0;
}
