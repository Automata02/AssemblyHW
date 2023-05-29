#include <iostream>

long long f2(int x)
{
    long long sum = 0;
    for (int i = 1; i <= x; ++i)
    {
        sum += i * (i + 1);
    }
    return sum;
}

int main()
{
    int x;
    std::cout << "Enter a value for x: ";
    std::cin >> x;

    long long result = f2(x);
    std::cout << "The value of the function f2 at x = " << x << " is: f2(" << x << ") = " << result << std::endl;

    return 0;
}
