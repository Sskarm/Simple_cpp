#include <iostream>

int main()
{
    int num = 0;
    std::cout << "Enter any number:" << std::endl;
    std::cin >> num ;
    if (num > 10)
    {
        std::cout << "your number is higher than 10." ;
    }
    else
    {
        std::cout << "your number is lower than 10." ;
    }
    return 0;
}