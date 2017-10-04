#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <iostream>
#include <cmath>
#include <sstream>
#include <complex>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:64000000")

typedef long long int64;
typedef unsigned long long uint64;

#define y1 _dsfkjdsfksdj
#define y0 _sfsdkfdop

typedef unsigned uint;
typedef vector<int64> vi64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int64,int64> pii64;
typedef pair<int,pii> piii;
typedef pair<pii,pii> piiii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;

inline void ans(string s)
{
    cout << s << endl;
    exit(0);
}

const int MAXN = 305;

int n;
int X, Y, Z;
int f[MAXN][MAXN];

int rec(int x, int y)
{
    if (f[x][y] != -1) return f[x][y];

    for (int dx = 1; dx <= x; ++dx)
    {
        if (!rec(x - dx, y)) return f[x][y] = 1;
    }

    for (int dy = 1; dy <= y; ++dy)
    {
        if (!rec(x, y - dy)) return f[x][y] = 1;
    }

    for (int d = 1; d <= min(x, y); ++d)
    {
        if (!rec(x - d, y - d)) return f[x][y] = 1;
    }

    return f[x][y] = 0;
}

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    cin >> n;

    if (n == 1)
    {
        cin >> X;
        if (X)
            ans("BitLGM");
        else
            ans("BitAryo");
    }

    if (n == 3)
    {
        cin >> X >> Y >> Z;
        if (X ^ Y ^ Z)
            ans("BitLGM");
        else
            ans("BitAryo");
    }

    cin >> X >> Y;
    memset(f, -1, sizeof f);
    if (rec(X, Y))
    {
        for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++)cout<<f[i][j];cout<<endl;}
        ans("BitLGM");}
    else
        {
        for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++)cout<<f[i][j];cout<<endl;}
        ans("BitAryo");}

    return 0;
}
