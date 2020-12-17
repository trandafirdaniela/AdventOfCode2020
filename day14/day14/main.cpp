#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
using namespace std;


ifstream file("in.txt");
string s, mask, msk, adr;
int val;
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
void rezolvare(string cuv)
{
    int i=0;
    while(i<cuv.size()&&cuv[i]!='X')
    {
        i++;
    }
    if (i == cuv.size())
    {
        mp[cuv] = val;
    }
    else
    {
        rezolvare(cuv.substr(0, i) + '0' + cuv.substr(i + 1));
        rezolvare(cuv.substr(0, i) + '1' + cuv.substr(i + 1));
    }

}
int main(void) {
    
    while (getline(file, s)) {
       
        if (s.substr(0, 4) == "mask")
            mask = s.substr(7);

        else {

            gasit = s.find("]");
            val = stoi(s.substr(gasit + 3));
            cout << val << " ";
            adr = convert(stoi(s.substr(4, gasit - 4)));
            for (int i = adr.size(); i < mask.size(); i++)
                adr = '0' + adr;
        
            msk = "";
            for (int i = mask.size(); i >= 0; i--) {
                if (mask[i] == '0')
                    msk = adr[i] + msk;
                else
                    msk = mask[i] + msk;
            }
            rezolvare(msk);
        }
    }
    int i = 0;
   
    for (auto i : mp)
        sum += i.second;
    cout << sum;
    return 0;
}
