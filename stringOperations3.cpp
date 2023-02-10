#include <iostream>
#include <string>
using namespace std;

int main()
{
    string readME;
    while (getline(cin,readME))
        if (!readME.empty())
            {
                cout << "the string is :" <<endl;
                cout <<readME << endl;
            }
        else 
            cout<< "The sting is empty"<< endl;
    return 0;
}