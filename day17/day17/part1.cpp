//#include <iostream>
//#include <fstream>
//#include <vector>
//using namespace std;
/////vector<vector<vector<int> > >
//
//bool a[105][105][105], b[105][105][105];
//int val;
//void f()
//{
//    swap(a, b);
//    memset(b, 0, sizeof b);
//    for (int x = 1; x <= 100; ++x)
//    {
//        for (int y = 1; y <= 100; ++y)
//        {
//            for (int z = 1; z <= 100; ++z)
//            {
//                int cnt = 0;
//                for (int dx = -1; dx <= 1; ++dx)
//                {
//                    for (int dy = -1; dy <= 1; ++dy)
//                    {
//                        for (int dz = -1; dz <= 1; ++dz)
//                        {
//                            if (dx == 0 && dy == 0 && dz == 0)
//                                continue;
//                            cnt += a[x + dx][y + dy][z + dz];
//                        }
//                    }
//                }
//                if (a[x][y][z]) {
//                    if (cnt == 2 || cnt == 3) b[x][y][z] = 1;
//                }
//                else {
//                    if (cnt == 3) b[x][y][z] = 1;
//                }
//            }
//        }
//    }
//}
//
//int main()
//{
//
//    char a;
//    for (int i = 41; i <= 48; ++i)
//    {
//        for (int j = 41; j <= 48; ++j)
//        {
//            cin >> a;
//            b[41][i][j] = a == '#';
//        }
//    }
//    for (int i = 1; i <= 6; ++i)
//        f();
//
//    for (int i = 1; i <= 100; ++i) {
//        for (int j = 1; j <= 100; ++j) {
//            for (int k = 1; k <= 100; ++k) {
//                val += b[i][j][k];
//            }
//        }
//    }
//    cout << val ;
//}
