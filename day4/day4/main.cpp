#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int n, i, j,cnt,nr;
char s[200],key[20];
ifstream fin("in.txt");
ofstream fout("out.txt");
void part1()
{
	while (fin.getline(s, 200))
	{
		if (strlen(s) <= 2)
		{
			if (cnt == 7)
			{
				nr++;
			}
			cnt = 0;
			continue;
		}
		char* cuv;
		cuv = strtok(s, " :");
		while (cuv)
		{
			if (cuv[0] != 'c')
			{
				cnt++;
			}
			cuv = strtok(NULL, " :");
			cuv = strtok(NULL, " :");
		}

	}
	if (cnt == 7)
	{
		nr++;
	}
	fout << nr;
}
void part2()
{
	while (fin.getline(s, 200))
	{
		if (strlen(s) <= 2)
		{
			if (cnt == 7)
			{
				nr++;
			}
			cnt = 0;
			continue;
		}
		char* cuv;
		cuv = strtok(s, " :");
	    while (cuv)
		{
			strcpy(key, cuv);
			cuv = strtok(NULL, " :");
			if (strcmp(key, "byr") == 0)
			{
				if (atoi(cuv) >= 1920 && atoi(cuv) <= 2002)
				{
					cnt++;
				}
			}
			if (strcmp(key, "iyr") == 0)
			{
				if (atoi(cuv) >= 2010 && atoi(cuv) <= 2020)
				{
					cnt++;
				}
			}
			if (strcmp(key, "eyr") == 0)
			{
				if (atoi(cuv) >= 2020 && atoi(cuv) <= 2030)
				{
					cnt++;
				}
			}
			if (strcmp(key, "hgt") == 0)
			{
				if (cuv[strlen(cuv) - 1] == 'n')
				{
					if (atoi(cuv) >= 59 && atoi(cuv) <= 76)
						cnt++;
				}
				else 
				if (cuv[strlen(cuv) - 1] == 'm')
				{
					if (atoi(cuv) >= 150 && atoi(cuv) <= 193)
						cnt++;
				}
			}
			if (strcmp(key, "hcl") == 0)
			{
				if (cuv[0] == '#')
				{
					int  k = 0;
					for (int i = 1; i < strlen(cuv); i++)
					{
						if ((cuv[i] >= '0' && cuv[i] <= '9') || (cuv[i] >= 'a' && cuv[i] <= 'f'))
							k++;
					}
					if (k == 6)
						cnt++;
				}
			}
			if (strcmp(key, "ecl") == 0)
			{
				if (!strcmp(cuv, "amb") ||
					!strcmp(cuv, "blu") ||
					!strcmp(cuv, "brn") ||
					!strcmp(cuv, "gry") ||
					!strcmp(cuv, "grn") ||
					!strcmp(cuv, "hzl") ||
					!strcmp(cuv, "oth"))
				{
					cnt++;
				}
			}
			if (strcmp(key, "pid") == 0)
			{
				int k = 0;
				for (int i = 0; i < strlen(cuv); i++)
				{
					if (cuv[i] >= '0' && cuv[i] <= '9')
						k++;
				}
				if (strlen(cuv) == 9 && k == 9)
					cnt++;
			}
			cuv = strtok(NULL, " :");
		}

		
	}
	if (cnt == 7)
	{
		nr++;
	}
	fout << nr;
}
int main()
{
	//part1();
	//part2();
	return 0;
}
