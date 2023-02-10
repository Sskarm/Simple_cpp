#include <iostream>

int main()
{
    int count = 1 , sum = 0 ;
    while (count <= 50)
        {
            sum += count;
            std::cout <<"Sum of " << count << " numbers is " << sum << std::endl; 
            count = count +1;

        }
    return 0;
}