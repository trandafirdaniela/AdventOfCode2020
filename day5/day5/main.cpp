#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int n, m,st,dr,l,c;
string s;
int maxim, fr[30005];
ifstream fin("in.txt");
ofstream fout("out.txt");
int main()
{
	while (fin >> s)
	{
		st = 0;
		dr = 127;
		for (int i = 0; i < 7; i++)
		{
			if (s[i] == 'F')
			{
				dr = (st + dr) / 2;
			}
			else
				st = (st + dr) / 2;
		}
		l = dr;
		st = 0;
		dr = 7;
		for (int i = 7; i <= 9; i++)
		{
			if (s[i] == 'L')
			{
				dr = (st + dr) / 2;
			}
			else
				st = (st + dr) / 2;
		}
		c = dr;
		fr[l * 8 + c]++;
		maxim = max(maxim, l * 8 + c);
	}
	//fout << maxim;
	for (int i = 0; i <= maxim; i++)
	{
		if (fr[i + 1] >= 1 && fr[i - 1] >= 1 && fr[i] == 0)
		{
			cout << i;
			return 0;
		}
	}
	
}