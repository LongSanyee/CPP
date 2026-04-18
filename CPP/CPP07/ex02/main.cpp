#include "Array.hpp"

int main()
{
    Array<int> arr(10);
    try
    {
        std::cout << arr[10] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << arr[5] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}