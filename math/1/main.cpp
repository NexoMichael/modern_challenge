#include <iostream>
#include <limits>
#include <algorithm>
#include <functional>

uint32_t sum1(const uint32_t limit)
{
    uint32_t result = 0;
    for (uint32_t i = 3; i < limit; i++)
        if ((i % 3 == 0) || (i % 5 == 0))
            result += i;
    return result;
}

uint32_t sum2(const uint32_t limit)
{
    uint32_t result = 0;
    for (uint32_t i = 3; i < limit; i += 3)
        result += i;
    for (uint32_t i = 5; i < limit; i += 5)
        if (i % 3 != 0)
            result += i;
    return result;
}

int main()
{
    uint32_t limit = 0;

    std::cout << "1. Sum of naturals divisible by 3 and 5\n";
    std::cout << "";
    while (limit == 0)
    {
        std::cout << "Enter a limit for the calculation (greater then 0): ";
        std::cin >> limit;
        if (std::cin.fail() || limit == 0)
        {
            std::cout << "Invalid input. Try again.\n";
            std::cin.clear();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << '\n';

    std::cout << "Sum of all naturals divisible by 3 or 5 is: " << sum1(limit) << '\n';
    std::cout << "Sum of all naturals divisible by 3 or 5 is: " << sum2(limit) << '\n';

    return 0;
}