#include <iostream>

extern "C" int f1(int x);

int main()
{
    int x;
    std::cout << "Enter a value for x: ";
    std::cin >> x;

    int result = f1(x);
    std::cout << "The value of the function f1 at x = " << x << " is: f(" << x << ") = " << result << std::endl;

    return 0;
}

extern "C" int f1(int x)
{
    __asm__(
        "cmp $3, %0\n"
        "jg .greater\n"
        "je .equal\n"
        "jl .less\n"

        ".greater:\n"
        "lea (%0, %0, 2), %0\n"
        "add $9, %0\n"
        "jmp .end\n"

        ".equal:\n"
        "mov $9, %0\n"
        "jmp .end\n"

        ".less:\n"
        "sub $3, %0\n"
        "sar $1, %0\n"
        "jmp .end\n"

        ".end:\n"
        : "+r"(x)
        :
        : "cc");

    return x;
}
