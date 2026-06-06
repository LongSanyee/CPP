#include "easyfind.hpp" 

int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    std::vector<char> s;
    s.push_back('a');
    s.push_back('b');
    s.push_back('c');
    s.push_back('d');
    std::cout << easyfind(v, 20) << std::endl;
    std::cout << easyfind(v, 50) << std::endl;
    std::cout << easyfind(s, 'a') << std::endl;
    std::cout << easyfind(s, 't') << std::endl;
}