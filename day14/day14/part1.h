#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
using namespace std;


ifstream file("in.txt");
string s, mask, msk, adr, val;
int gasit;
map<string, long long> mp;
long long sum = 0;

string convert(int n) {
    string cv = "";
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            cv += '1';
        else
            cv += '0';
    }
    return cv;
}

int main(void) {

    while (getline(file, s)) {
        if (s.substr(0, 4) == "mask")
            mask = s.substr(7);

        else {

            gasit = s.find("]");
            adr = s.substr(4, gasit - 4);

            val = convert(stoi(s.substr(gasit + 3)));
            for (int i = val.size(); i < mask.size(); i++)
                val = '0' + val;

            msk = "";
            for (int i = mask.size(); i >= 0; i--) {
                if (mask[i] == 'X')
                    msk = val[i] + msk;
                else
                    msk = mask[i] + msk;
            }

            mp[adr] = stoull(msk, 0, 2);
        }
    }
    for (auto i : mp)
        sum += i.second;
    cout << sum;
    return 0;
}
