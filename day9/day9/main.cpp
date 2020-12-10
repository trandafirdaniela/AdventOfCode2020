#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long x;
vector<long long> v;
int nrGasit;
long long maxim, minim;
vector<long long> sumaPartiala;
ifstream fin("in.txt");
ofstream fout("outt.txt");
int main()
{
    int nrGasit=-1;

    while (fin >> x) {
        v.push_back(x);
    }

    for (auto i = 25; i < v.size(); i++) {

        int ok = 0;

        for (int j = i - 25; j < i; j++)
            for (int k = i - 25; k < i; k++)
                    if ((j != k)&&(v[j] + v[k] == v[i]))
                        ok = 1;

        if (ok == 0)
            nrGasit = v[i];
    }

    fout <<"part1:"<< nrGasit << '\n';
    sumaPartiala.push_back(v[0]);

    for (int i = 1; i < v.size(); i++)
        sumaPartiala.push_back(sumaPartiala[i - 1] + v[i]);

    for (int i = 0; i < v.size(); i++)
        for (int j = i + 1; j < v.size(); j++)
            if (sumaPartiala[j] - sumaPartiala[i] == nrGasit) {

                 maxim =INT_MIN;
                 minim = INT_MAX;

                for (int k = j; k > i; k--) {
                    if (v[k] > maxim) maxim = v[k];
                    if (v[k] < minim) minim = v[k];
                }
                
                 fout << "Part2:" << maxim + minim << '\n';
                
                  
       
            }


    return 0;
}
    
    
    
    
    
    
    
    
    
  