#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
ifstream fin("in.txt");
ofstream fout("out.txt");
char s[400];
//map < char*, int> culoare;
char* v[10000];
map<string, int> mapa;
vector <pair<int,int> > L[10000];
char* start;
int nrCulori;
int nr, fr[10000];
string convertString(char* x) {
	string r = "";
	for (int i = 0; i < strlen(x); i++)
		r += x[i];
	return r;
}
void adaugmuchie(char* a, char* b,int val) {
	string A = convertString(a);
	string B = convertString(b);
	if (mapa.find(A) == mapa.end()) {
		mapa[A] = ++nrCulori;
	}
	if (mapa.find(B) == mapa.end()) {
		mapa[B] = ++nrCulori;
	}
	L[mapa[A]].push_back({ mapa[B],val });
}
int dfs(int nod) {
	fr[nod] = 1;
	int r = 0;
	for (auto it : L[nod]) {
			r+=it.second*dfs(it.first);
	}
	return r +1;
}
int main()
{
	int i = 0;
	while (fin.getline(s, 400))

	{
		char* cuv;
		cuv = strtok(s, " ,.");
		i = 0;
		while (cuv)
		{	
			++i;
			if (strcmp(cuv, "no") == 0 || strcmp(cuv, "other") == 0) {
				break;
			}

			v[i - 1] = cuv;
			//cout << cuv << " ";
			if ((strcmp(cuv, "bags") == 0)|| (strcmp(cuv, "bag") == 0))
			{

				int x = i - 3;
				int y = i - 2;
				cout << x << " " << y << endl;
				*(v[y] - 1) = ' ';
				if (x == 0) {
					start = v[x];
				}
				else {
					int val = atoi(v[i - 4]);
					//cout << v[x];
					adaugmuchie(start, v[x],val);
				}
				//cout << x << " " << y << endl;
				//.push_back(v[x],)
				
			}
			cuv = strtok(NULL, "  , . ");
		}
	}
	int st = mapa.find("shiny gold")->second;
	cout<<dfs(st)-1;
	return 0;
}