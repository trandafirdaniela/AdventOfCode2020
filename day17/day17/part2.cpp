#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
///vector<vector<vector<int> > >

bool a[32][32][32][32], b[32][32][32][32];
int val;
ifstream fin("in.txt");
void f()
{
    swap(a, b);
    memset(b, 0, sizeof b);
    for (int x = 1; x <= 30; ++x)
    {
        for (int y = 1; y <= 30; ++y) 
        {
            for (int z = 1; z <= 30; ++z) 
            {
                for (int k = 1; k <= 30; ++k)
                {
                    int cnt = 0;
                    for (int dx = -1; dx <= 1; ++dx) 
                    {
                        for (int dy = -1; dy <= 1; ++dy)
                        {
                            for (int dz = -1; dz <= 1; ++dz) 
                            {
                                for (int dk = -1; dk <= 1; ++dk) 
                                {
                                    if (dx == 0 && dy == 0 && dz == 0 && dk == 0)
                                        continue;
                                    cnt += a[x + dx][y + dy][z + dz][k + dk];
                                }
                            }
                        }
                    }
                    if (a[x][y][z][k]) {
                        if (cnt == 2 || cnt == 3) b[x][y][z][k] = 1;
                    }
                    else {
                        if (cnt == 3) b[x][y][z][k] = 1;
                    }
                }
            }
        }
    }
}

int main() 
{
   
    char a;
    for (int i = 15; i <= 22; ++i) 
    {
        for (int j = 15; j <= 22; ++j)
        {
            fin >> a;
            b[15][15][i][j] = a == '#';
        }
    }
    for (int i = 1; i <= 6; ++i)
 
        f();
    
    val = 0;
    for (int i = 1; i <= 30; ++i) 
    {
        for (int j = 1; j <= 30; ++j)
        {
            for (int k = 1; k <= 30; ++k)
            {
                for (int l = 1; l <= 30; l++)
                {
                    val += b[i][j][k][l];
                }
            }
        }
    }
    //enter rez
    cout << val ;
}
