#include "easyfind.hpp" 

int main()
{
    std::vector<int> v = {10, 20, 30, 40};
    std::vector<char> s = {'a', 'b', 'c', 'd'};
    std::cout << easyfind(v, 20) << std::endl;
    std::cout << easyfind(v, 50) << std::endl;
    std::cout << easyfind(s, 'a') << std::endl;
    std::cout << easyfind(s, 't') << std::endl;
}