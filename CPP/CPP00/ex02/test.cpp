#include <ctime>
#include <iomanip>
#include <iostream>

int main()
{
    std::time_t now = std::time(NULL);
	std::tm* localTime = std::localtime(&now);

	std::cout << "[" << localTime->tm_yday << "] ";
}