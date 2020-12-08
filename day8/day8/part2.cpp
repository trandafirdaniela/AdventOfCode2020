#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

// set up input
ifstream fin("in.txt");
ofstream fout("out.txt");
string line, opt, curent = "";
int rez = 0;
int val, idx = 0;
vector<pair<string, int>> comenzi;
map<int, bool> viz;
bool notBucla()
{
    idx = 0;
    curent = comenzi[0].first;
    for (int i = 0; i < comenzi.size(); i++)
    {
        if (curent == "jmp")
            idx += comenzi[idx].second;
        else
            idx++;
        if (idx == comenzi.size() - 1)
            return true;
        curent = comenzi[idx].first;
    }
    return false;
}

void bucla()
{
    for (int i = 0; i < comenzi.size(); i++)
    {
        if (comenzi[i].first == "acc")
        {
            continue;
        }
        else if (comenzi[i].first == "jmp")
        {
            //se schimba
            comenzi[i].first = "nop";
            if (!notBucla())
            {
                //nu se face schimbare
                comenzi[i].first = "jmp";

            }
            else break;
        }
        else if (comenzi[i].first == "nop")
        {
            comenzi[i].first = "jmp";
            if (!notBucla())
            {
                //nu se face schimbare
                comenzi[i].first = "nop";

            }
            else break;
        }
    }
}
int main(void) {
    while (getline(fin, line)) {

        opt = line.substr(0, 3);
        val = stoi(line.substr(5, line.size() - 5));
        if (line[4] == '-')
            val *= -1;
        comenzi.push_back(make_pair(opt, val));
    }
    bucla();

    idx = 0;
    curent = comenzi[0].first;
    while (idx!=comenzi.size()-1)
    {
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
    rez += comenzi[idx].second;
    cout << rez-1;
    return 0;
}