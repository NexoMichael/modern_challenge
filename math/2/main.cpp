#include <iostream>
#include <limits>
#include <numeric>

uint32_t gcd1(const uint32_t a, const uint32_t b)
{
    if (a == b)
        return a;
    if (a > b)
        return gcd1(a - b, b);
    else
        return gcd1(b - a, a);
}

uint32_t gcd2(uint32_t a, uint32_t b)
{
    while (a != b)
        if (a > b)
            a -= b;
        else
            b -= a;
    return a;
}

int main()
{
    uint32_t a = 0, b = 0;
    std::cout << "2. greatest common divisor\n";
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

    std::cout << "GCD(" << a << ", " << b << ") = " << gcd1(a, b) << "\n";
    std::cout << "GCD(" << a << ", " << b << ") = " << gcd2(a, b) << "\n";
    std::cout << "GCD(" << a << ", " << b << ") = " << std::gcd(a, b) << "\n";
    return 0;
}