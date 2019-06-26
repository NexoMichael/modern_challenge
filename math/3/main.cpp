#include <iostream>
#include <limits>
#include <numeric>

uint32_t lcm1(const uint32_t a, const uint32_t b)
{
    if (a == 0 && b == 0)
        return 0;

    return uint32_t((uint64_t(a) * uint64_t(b)) / std::gcd(a, b));
}

int main()
{
    uint32_t a = 0, b = 0;
    std::cout << "3. least common multiply\n";
    std::cout << "";

    while (a == 0 || b == 0)
    {
        std::cout << "Enter two numbers (greater then 0): ";
        std::cin >> a >> b;
        if (std::cin.fail() || a == 0 || b == 0)
        {
            std::cout << "Invalid input. Try again.\n";
            std::cin.clear();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "\n";

    std::cout << "LCM(" << a << ", " << b << ") = " << lcm1(a, b) << "\n";
    std::cout << "LCM(" << a << ", " << b << ") = " << std::lcm(a, b) << "\n";
    return 0;
}