#include <iostream>

int main()
{
    int price = 0 ;
    std::cout << "Enter fifa selling price:" << std::endl;
    std::cin >> price ; 
    std::cout << "The money you get after tax is " << 0.95*price << "."  ;
    return 0 ;
}