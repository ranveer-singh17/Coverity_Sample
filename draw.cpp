#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream myfile;
	myfile.open("draw.txt");
	string line;
	while(myfile.open("draw.txt"))
	{
		getline(myfile, line);
		cout << line << endl;
	}
	return 0;
}
