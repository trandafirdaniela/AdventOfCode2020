#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// stackoverflow ->evaluating arithmetic expressions from string
ifstream fin("in.txt");
ofstream fout("out.txt");
long long fact(string& _s);
long long numar(string& _s);
long long expresie(string& _s);
long long advancedMath(string& _s);

long long expresie(string& _s)
{
	long long rez = advancedMath(_s);

	while (_s[0] == '*')
	{
			_s.erase(_s.begin(), _s.begin() + 2); // remove the sign and the space after
			rez *= advancedMath(_s);
		
	}

	return rez;
}

long long fact(string& _s)
{
	if (_s[0] >= '0' && _s[0] <= '9')
	{
		return numar(_s);
	}
	else if (_s[0] == '(')
	{
		_s.erase(_s.begin(), _s.begin() + 1); // remove the open bracket
		long long rez = expresie(_s);
		_s.erase(_s.begin(), _s.begin() + 1); // remove the closed bracket and the space after

		if (_s[0] == ' ')
		{
			_s.erase(_s.begin(), _s.begin() + 1); // remove the space after the closed bracket (if exists)
		}

		return rez;
	}
}
long long advancedMath(string& _s)
{
	long long rez = fact(_s);

	while (_s[0] == '+')
	{
		_s.erase(_s.begin(), _s.begin() + 2); // remove the sign and the space after
		rez += fact(_s);
	}
	return rez;
}
long long numar(string& _s)
{
	long long number = 0;
	while (_s[0] >= '0' && _s[0] <= '9')
	{
		number = number * 10 + (_s[0] - '0');
		_s.erase(_s.begin(), _s.begin() + 1); // remove the digit
	}

	if (_s[0] == ' ')
	{
		_s.erase(_s.begin(), _s.begin() + 1); // remove the space after the number (if exists)
	}

	return number;
}
long long sum;

int main()
{


	string s;
	while (getline(fin, s))
	{
		s += " ";
		sum += expresie(s);
	}
	cout<< sum;
}