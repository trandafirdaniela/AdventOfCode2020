#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("in.txt");
string s;
vector<string> v;
vector<vector<char>> scaune, scauneDupa;
int latime = 0, lungime = 0;

int ocupat(int i, int j) {
    int nr= 0;
    for (int b = i - 1; b <= i + 1; b++) 
        for (int c = j - 1; c <= j + 1; c++) 
            if ((b != i || c != j) && scaune[b][c] == '#') {
                nr++;
            }
        
    
    return nr;
}

bool egale() {
    bool ok = 0;
    for (int i = 0; i < scaune.size(); i++)
        for (int j = 0; j < scaune[i].size(); j++)
            if (scaune[i][j] != scauneDupa[i][j])
            {
                ok = 1;
                break;
            }
    return ok == 0;
    
}

void process() {
    while (1) {
        // resetare scauneDupa
        scauneDupa = scaune;

//update scaune dupa
        for (int i = 0; i < scaune.size(); i++)
        {
            for (int j = 0; j < scaune[i].size(); j++)
            {
                if (scaune[i][j] == 'L')
                {
                    if (ocupat(i, j) == 0)
                    {
                        scauneDupa[i][j] = '#';
                    }
                }
                //  dir
                else if (scaune[i][j] == '#')
                {
                    if (ocupat(i, j) >= 4) {
                        scauneDupa[i][j] = 'L';
                    }
                }
                else
                    scauneDupa[i][j] = '.';
            }
        }
        //final
        if (egale())
            break;

        // update scaune
        scaune = scauneDupa;
    }
}



int main(void) {
    lungime += 2;
    while (getline(fin, s)) {
        v.push_back(s);
        latime = s.size();
        lungime++;

    }
    latime += 2;
    scaune.resize(lungime);
    for (int i = 0; i < scaune.size(); i++)
        scaune[i].resize(latime);
    for (int i = 0; i < scaune.size(); i++)
        for (int j = 0; j < scaune[i].size(); j++)
            scaune[i][j] = '.';

    for (int i = 1; i < scaune.size() - 1; i++) {
        for (int j = 1; j < scaune[i].size() - 1; j++) {
            scaune[i][j] = v[i - 1][j - 1];
        }
    }
    process();
    int nr= 0;
    for (int i = 0; i < scaune.size(); i++)
        for (int j = 0; j < scaune[i].size(); j++)
            if (scaune[i][j] == '#')
                nr++;
    cout << nr;
    
    return 0;
}