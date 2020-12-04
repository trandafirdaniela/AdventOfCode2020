#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

ofstream fout("out.txt");
ifstream fin("in.txt");

long long  a[1000][100];
int main() {
    long long N = 323;
    for (long long  i = 0; i < N; i++) {
        string c; 
        fin >> c;
        for (long long j = 0; j < c.size(); j++)
            a[i][j] = c.at(j) == '#' ? 1 : 0;
    }
    long long cnt = 0;
    for (long long i = 0, j = 0; i < N; i++, j += 3)
        if (a[i][j % 31] == 1)
            cnt++;
    fout << cnt;
}