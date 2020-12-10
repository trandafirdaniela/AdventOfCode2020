#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fin("in.txt");
ofstream fout("out.in");
long long n;
vector<long long > v;
vector<long long int> dp;
int main()

{

fout<<"daaaa";
    v.push_back(0);
    while(fin>>n)
    {
        v.push_back(n);
    }
    sort(v.begin(),v.end());

    int x = 0, y=0;
    for(int i=1; i<v.size(); i++)
        if(v[i]-v[i-1]!=1)
            y++;
        else x++;

    cout<<"part1:"<<x*(y+1)<<'\n';
    dp.push_back(1);
    for(int i=1; i<v.size(); i++)
    {
        int cnt = 0;
        if(i-1>=0 && v[i]-v[i-1]<=3)
            cnt++;
        if(i-2>=0 && v[i]-v[i-2]<=3)
            cnt++;
        if(i-3>=0 && v[i]-v[i-3]<=3)
            cnt++;

        if(cnt==1)
            dp[i] = dp[i-1];
        else if(cnt==2)
            dp[i] = dp[i-1] + dp[i-2];
        else if(cnt==3)
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

    }

    cout<<"part2:"<<dp[v.size()-1];
    return 0;
}
