#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
int n, m;
vector<int> v;
int nr;
ifstream fin("in.txt");
ofstream fout("out.txt");
string s,cuv;
 int fr[205];
void f()
{
	for (int i = 1; i < 200; i++)
	{
		fr[i] = 0;
	}
}
int main()
{
	while (fin >> n)
	{
		fin >> m;
		fin >> cuv;
		fin >> s;
		if ((s[n - 1] == cuv[0] || s[m - 1] == cuv[0]) && (s[n - 1] != s[m - 1]))
			nr++;
		
		

	}
	fout << nr;
}