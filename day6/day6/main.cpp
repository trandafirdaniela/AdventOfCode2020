#include <iostream>
#include <string>
#include <fstream>
using namespace std; 
int fr[210], nr, cnt,sum1,sum2;
string s;
ifstream fin("in.txt");
ofstream fout("out.txt");
int main()
{
	while (getline(fin, s))
	{
		if (s=="")
		{
			for (int i = 'a'; i <= 'z'; i++)
			{
				
				if (fr[i])
				   sum1++;
				if (fr[i]==cnt)
				   sum2++;
				
			}
			for (int i = 'a'; i <= 'z'; i++)
			{
				fr[i] = 0;
			}
			cnt = 0;

		}
		else
		{
			cnt++;
			for (int i = 0; i < s.size(); i++)
			{
				fr[s[i]]++;
			}
		}
	 }
	for (int i = 'a'; i <= 'z'; i++)
	{
		
		if (fr[i])
			sum1++; 
		if (fr[i]==cnt)
			sum2++;
	}
	fout << sum1 << "\n"<<sum2;;
}