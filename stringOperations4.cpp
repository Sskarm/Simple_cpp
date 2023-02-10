#include <iostream>
#include <string>
using namespace std;

int main()
{
    string readME;
    while (getline(cin,readME))
    {
        auto len = readME.size();
        cout << "Lenght of this string " << len << endl;
    }
    return 0;
}
