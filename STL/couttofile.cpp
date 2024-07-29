#include <iostream>
#include <fstream>

int main()
{
    std::ofstream file("output.txt");
    if (!file)
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    std::streambuf* original_buf = std::cout.rdbuf();
    std::cout.rdbuf(file.rdbuf());

    std::cout << "This is being printed to the file instead of the terminal." << std::endl;

    std::cout.rdbuf(original_buf);


    std::cout << "This is being printed to the terminal." << std::endl;
    return 0;
}
