#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
# define PI  3.14159265358979323846
using namespace std;
char act;
string s;
int x, y;
vector<pair<char, int>> actiuni;
int nx, ny,wx=10,wy=1, unghi;
int _sin, _cos;
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
		//waypoint
		if (act == 'N')
			wy += p.second;
		if (act == 'E')
			wx += p.second;
		if (act == 'S')
			wy -= p.second;
		if (act == 'W')
			wx -= p.second;
		//nava
		if (act == 'F')
		{
			nx = (wx - x) * p.second;
			ny = (wy - y) * p.second;
			x += nx;
			y += ny;
			wx += nx;
			wy += ny;
		}

		//directie dif
		if ((act == 'L') || (act == 'R'))
		{
			unghi = p.second;
			if (act == 'R')
				unghi *= -1;
			_sin = sin(unghi * PI / 180);
			_cos = cos(unghi * PI / 180);
			wx -= x;
			wy -= y;
			// rot
			nx = wx * _cos - wy * _sin;
			ny = wx * _sin + wy * _cos;
			//back
			wx = nx + x;
			wy = ny + y;
		}

	}
	cout << abs(x) + abs(y);
}