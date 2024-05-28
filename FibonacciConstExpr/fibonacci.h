#ifndef FIBONACCI_H
#define FIBONACCI_H

template<int N>
struct Fibonacci
{
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

// case - fibonacci 1
template<>
struct Fibonacci<1>
{
    static constexpr int value = 1;
};

// case - fibonacci 0
template<>
struct Fibonacci<0>
{
    static constexpr int value = 0;
};

#endif // FIBONACCI_H