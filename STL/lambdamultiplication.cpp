#include <iostream>

int main() {

    auto mult = [](int x)
    {
        return [x](int y)
        {
            return x * y;
        };
    };

    std::cout << "Result of mult(5)(6): " << mult(5)(6) << std::endl;

    return 0;
}
