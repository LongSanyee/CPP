#include "iter.hpp"

int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    char c[] = "hello";
    size_t len = 5;
    iter(nums, len, func<int>);
    iter(nums, len, print<int>);
    std::cout << std::endl;
    iter(c, len, func<char>);
    iter(c, len, print<char>);
}