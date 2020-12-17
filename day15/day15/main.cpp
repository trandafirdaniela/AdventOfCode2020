
#include <iostream>
#include<vector>
#include <map>
#pragma once
using namespace std;
int ant, val, ultim;
vector<int> input;
map<int, vector<int>> mp;

int main()
{
	input = { 13,16,0,12,15,1 };
	for (int i = 0; i < input.size(); i++)
	{
		mp[input[i]].push_back(i);

	}
	ant = 0;
	///	part1
	///  valoare = 2020;
	// part2 
	/// valoare = 30000000
	int valoare = 30000000;
	for (int i = input.size(); i < valoare; i++)
	{
		ultim = ant;
		int urm;
		if ((int)mp[ultim].size() == 1)
		{
			urm = 0;
		}
		else
			urm = mp[ultim][1] - mp[ultim][0];
		if ((int)mp[urm].size() == 2)
		{
			mp[urm][0] = mp[urm][1];
			mp[urm][1] = i;
		}
		else
			mp[urm].push_back(i);
		ant = urm;
	}

	cout << ant << "\n";
	return 0;
}
