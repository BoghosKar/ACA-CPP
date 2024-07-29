#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx;

unsigned long long factorial_partial(int start, int end)
{
    unsigned long long partial_result = 1;
    for (int i = start; i <= end; ++i)
    {
        partial_result *= i;
    }
    return partial_result;
}

unsigned long long calculate_factorial(int n, int num_threads)
{
    std::vector<std::thread> threads;
    std::vector<unsigned long long> partial_results(num_threads);
    int chunk_size = n / num_threads;

    for (int i = 0; i < num_threads; ++i)
    {
        int start = i * chunk_size + 1;
        int end = (i == num_threads - 1) ? n : (i + 1) * chunk_size;
        threads.emplace_back([&partial_results, i, start, end] {
            partial_results[i] = factorial_partial(start, end);
        });
    }

    for (auto& t : threads)
    {
        t.join();
    }

    unsigned long long factorial_result = 1;
    for (const auto& result : partial_results)
    {
        factorial_result *= result;
    }

    return factorial_result;
}

int main()
{
    int a = 5;
    int n = 10;
    int num_threads = 4;

    unsigned long long result_a = calculate_factorial(a, num_threads);
    std::cout << "Factorial of " << a << " is: " << result_a << std::endl;

    unsigned long long result_n = calculate_factorial(n, num_threads);
    std::cout << "Factorial of " << n << " is: " << result_n << std::endl;

    return 0;
}
