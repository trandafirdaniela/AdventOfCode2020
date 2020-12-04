#include <iostream>
#include <fstream>
#include <vector>
using namespace std; 
ifstream fin("in.txt");
ofstream fout("out.txt");
int n, m, sum, prod=1;
vector <int> v1, v2;
int main()
{
	while (fin >> n)
	{
		v1.push_back(n);
	
	}
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = i + 1; j < v1.size(); j++)
			for (int k = j + 1; k < v1.size(); k++)
			{
				if (v1[i] + v1[j]+v1[k] == 2020)
				{
					cout << v1[j] * v1[i]*v1[k];
					return 0;
				}
			}
	}
}