#include <iostream>

extern "C" long long f2(int x);

int main()
{
    int x;
    std::cout << "Enter a value for x: ";
    std::cin >> x;

    long long result = f2(x);
    std::cout << "The value of the function f2 at x = " << x << " is: f2(" << x << ") = " << result << std::endl;

    return 0;
}

extern "C" long long f2(int x)
{
    long long sum = 0;
    int i;
    __asm__(
        "movl $1, %%ecx\n"
        "movq $0, %%rax\n"

        "start_loop:\n"
        "cmp %%ecx, %1\n"
        "jg end_loop\n"

        "imul %%ecx, %%ecx\n"
        "add %%ecx, %%ecx\n"
        "add %%ecx, %%rax\n"

        "inc %%ecx\n"
        "jmp start_loop\n"

        "end_loop:\n"
        "movq %%rax, %0\n"

        : "=r"(sum), "=r"(x)
        : "1"(x)
        : "%rax", "%rcx", "cc");

    return sum;
}
