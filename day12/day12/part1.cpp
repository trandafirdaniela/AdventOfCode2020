#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
char act;
string s;
int x, y, directie;
vector<pair<char, int>> actiuni;

ifstream fin("in.txt");
ofstream fout("out.txt");

int main()
{
	while (getline(fin, s))
	{
		actiuni.push_back({ s[0],stoi(s.substr(1)) });
	}
	for (auto p : actiuni)
	{
		act = p.first;
		if (act == 'F')
		{
			directie = directie % 360 + 360;
			if (directie % 360 == 0)
			{
				act = 'E';
			}
			else if (directie % 360 == 90)
			{
				act = 'N';
			}
			if (directie % 360 == 180)
				act = 'W';
			if (directie % 360 == 270)
				act = 'S';
		}
		if (act == 'N')
			y += p.second;
		if (act == 'E')
			x += p.second;
		if (act == 'S')
			y -= p.second;
		if (act == 'W')
			x -= p.second;
		//directie dif
		if (act == 'L')
			directie += p.second;
		if (act == 'R')
			directie -= p.second;
	}
	cout << abs(x) + abs(y);
}