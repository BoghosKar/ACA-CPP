#include <iostream>
#include <utility>

template <typename T1, typename T2>
std::pair<T1, T2> make_pair(T1 first, T2 second)
{
    return std::pair<T1, T2> (first, second);
}

int main()
{   
    auto myPair1 = make_pair(10, "ten");
    auto myPair2 = make_pair(20, "twenty");

    std::cout << "Pair: (" << myPair1.first << ", " << myPair1.second << ")" << std::endl;
    std::cout << "Pair: (" << myPair2.first << ", " << myPair2.second << ")" << std::endl;

    return 0;
}
