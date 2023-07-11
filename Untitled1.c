#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream myfile ("draw.txt");
    string line;
    if(myfile.is_open())
    {
        while(getline(myfile, line))
        {
            cout << line;

        }
    }
}
