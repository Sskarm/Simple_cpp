#include <iostream>

int main()
{
    int count = 1 , sum = 0 , ceiling = 0;
    std::cout << "Give me the ceiling of the sum : " << std::endl;
    std::cin >> ceiling ;
    while (count <= ceiling )
        {
            sum += count;
            std::cout <<"Sum of " << count << " numbers is " << sum << "." <<  std::endl; 
            count = count +1;

        }
    return 0;
}