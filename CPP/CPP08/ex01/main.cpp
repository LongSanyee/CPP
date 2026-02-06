#include "Span.hpp"

int main()
{
    std::vector<int> t = {900, 800, 700, 600, 500, 400};
    Span sp = Span(13);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(15);
    sp.addNumber(t.begin(), t.end());
    sp.print();

    std::cout << "Shortest span is: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span is: " <<sp.longestSpan() << std::endl;
    return 0;
}
