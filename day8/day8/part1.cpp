#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
ifstream fin("in.txt");
ofstream fout("out.txt");
string line, opt, curent = "";
int rez = 0;
int val, idx = 0;
vector<pair<string, int>> comenzi;
map<int, bool> viz;

int main(void) {
    while (getline(fin, line)) {

        opt = line.substr(0, 3);
        val = stoi(line.substr(5, line.size() - 5));
        if (line[4] == '-')
            val *= -1;
        comenzi.push_back(make_pair(opt, val));
    }
    curent = comenzi[0].first;
    while (1) {
        if (viz[idx])
            break;
        viz[idx] = 1;
        if (curent == "acc") {
            rez += comenzi[idx].second;
            idx++;
        }
        else if (curent == "jmp") {
            idx += comenzi[idx].second;
        }
        else if (curent == "nop") {
            idx++;
        }
        curent = comenzi[idx].first;
    }
    fout << rez;
    return 0;
}