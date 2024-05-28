#ifndef FIBONACCI_H
#define FIBONACCI_H

constexpr int fibonacci(int n)
{
    return (n <= 1) ? n : (fibonacci(n - 1) + fibonacci(n - 2));
}

#endif // FIBONACCI_H