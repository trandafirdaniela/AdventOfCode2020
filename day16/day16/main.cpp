#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int npos = -1;
vector<vector<int>> rez;
vector<int> ticket;
long long n, pos, first, second, idx, out;
string s, f, num;
vector<pair<int, vector<int>>> candidat;
vector<pair<string, vector<pair<int, int>>>> field;

vector<int> fieldIndex;
vector<string> v;

ifstream fin("in.txt");
ofstream fout("out.txt");

bool build(int i, int util)
{
    if (i == n) 
        return true;
    
    for (auto j : candidat[i].second)
    {
        if (!(util & (1 << j)))
        {
            fieldIndex[candidat[i].first] = j;
            if (build(i + 1, util | (1 << j)))
                return true;
            fieldIndex[candidat[i].first] = -1;
        }
    }

    return false;
}

int main() 
{
        while (getline(fin, s))
        {
        v.push_back(s);
       }

    int tip = 0;
    for (auto s : v) 
    {
        if (s == "")
        {
            tip++;  continue;
        }

        if (tip == 0)
        {
             pos = s.find(":");
             f = s.substr(0, pos);
            pos = s.find("-");
         
            field.push_back({ f, vector<pair<int, int>>() });
             idx = field.size() - 1;

            for (int i = pos - 1; i >= 0 && (s[i] != ' '); i--)
            {
                num += s[i];
            }
            reverse(num.begin(), num.end());
            first = stoi(num);
            num = "";
            
            for (int i = pos + 1; i < s.size() && (s[i] != ' '); i++)
            {
                num += s[i];
            }

            second = stoi(num);
            num = "";
            field[idx].second.push_back({ first, second });

            pos = s.find("-", pos + 1);
            for (int i = pos - 1; i >= 0 && (s[i] != ' '); i--) 
            {
                num += s[i];
            }

            reverse(num.begin(), num.end());
            first = stoi(num);
            num = "";
            for (int i = pos + 1; i < s.size() && (s[i] != ' '); i++) 
            {
                num += s[i];
            }
            second = stoi(num);
            num = "";
            field[idx].second.push_back({ first, second });

        }
        if (tip == 1)
        {
            if (s == "your ticket:") 
                continue;
            n = field.size();
            for (int i = 0; i < s.size(); i++) 
            {
                num = "";
                while (i < s.size() && s[i] != ',')
                    num += s[i++];
                ticket.push_back(stoi(num));

            }
        }
        if (tip == 2) {
            if (s == "nearby tickets:") 
                continue;
            vector<int> nearby;
            
            for (int i = 0; i < s.size(); i++)
            {
                num = "";
                while (i < s.size() && s[i] != ',')
                    num += s[i++];
                nearby.push_back(stoi(num));
            }
           
            rez.push_back(nearby);
        }
    }

    for (int k = 0; k < rez.size(); k++)
    {
        for (int i = 0; i < n; i++)
        {
            bool ok = false;
            for (int j = 0; j < n; j++)
            {
                for (auto range : field[j].second)
                {
                    if (range.first <= rez[k][i] && range.second >= rez[k][i])
                    {
                        ok = true;
                    }
                }
            }
            if (ok==0) {
                rez.erase(rez.begin() + k);
                k--;
                break;
            }
        }
    }

   
    rez.push_back(ticket);

    
    for (int i = 0; i < n; i++) 
    {
        candidat.push_back({ i, vector<int>() });
        for (int j = 0; j < n; j++)
        {
            bool column = true;
            for (int k = 0; k < (int)rez.size(); k++)
            {
                bool element = false;
                for (auto range : field[i].second) 
                {
                    if (range.first <= rez[k][j] && range.second >= rez[k][j])
                    {
                        element = true;
                        break;
                    }
                }
                if (!element) 
                {
                    column= false;
                    break;
                }
            }
            if (column)
            {
                candidat[i].second.push_back(j);
            }
        }
    }
    
    /// comp
    sort(candidat.begin(), candidat.end(), [&](const pair<int, vector<int>>& a, const pair<int, vector<int>>& b)
        {
        return a.second.size() < b.second.size();
        });

    fieldIndex.assign(n, -1);
    build(0, 0);
    long long out = 1;
    for (int i = 0; i < n; i++)
    {
        if (field[i].first.find("departure") != npos)
        {
            out *= ticket[fieldIndex[i]];
        }
    }
   
    cout << out;

    return 0;
}