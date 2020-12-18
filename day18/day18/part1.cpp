//#include <iostream>
//#include <string>
//#include <fstream>
//#include <vector>
//using namespace std;
//
//// stackoverflow ->evaluating arithmetic expressions from string
//ifstream fin("in.txt");
//ofstream fout("out.txt");
//long long fact(string& _s);
//long long numar(string& _s);
//long long expresie(string& _s);
//
//long long expresie(string& _s)
//{
//	long long rez = fact(_s);
//
//	while (_s[0] == '+' || _s[0] == '*')
//	{
//		if (_s[0] == '+')
//		{
//			//_s.erase(_s.begin(), _s.begin() + 2); 
//			rez += fact(_s);
//		}
//		else
//		{
//			_s.erase(_s.begin(), _s.begin() + 2); 
//			rez *= fact(_s);
//		}
//	}
//
//	return rez;
//}
//
//long long fact(string& _s)
//{
//	if (_s[0] >= '0' && _s[0] <= '9')
//	{
//		return numar(_s);
//	}
//	else if (_s[0] == '(')
//	{
//		_s.erase(_s.begin(), _s.begin() + 1); 
//		long long rez = expresie(_s);
//		_s.erase(_s.begin(), _s.begin() + 1); 
//
//		if (_s[0] == ' ')
//		{
//			_s.erase(_s.begin(), _s.begin() + 1); 
//		}
//
//		return rez;
//	}
////}
//
//long long numar(string& _s)
//{
//	long long number = 0;
//	while (_s[0] >= '0' && _s[0] <= '9')
//	{
//		number = number * 10 + (_s[0] - '0');
//		_s.erase(_s.begin(), _s.begin() + 1); 
//	}
//
//	if (_s[0] == ' ')
//	{
//		_s.erase(_s.begin(), _s.begin() + 1); 
//	}
//
//	return number;
//}
//long long sum;
//
//int main()
//{
//
//
//	string s;
//	while (getline(fin, s))
//	{
//		s += " ";
//		sum += expresie(s);
//	}
//	cout << sum;
//}