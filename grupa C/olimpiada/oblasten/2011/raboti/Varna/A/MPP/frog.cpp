/*
TASK: frog
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef pair<int , int> Point;

int n;
Point m[16];
int ans = 2000000000;

inline int max(int a,int b)
{
    if(a < b) return b;
    return a;
}

inline int abs(int a)
{
    if(a < 0) return -a;
    return a;
}

inline int dist(Point A,Point B) { return max(abs(A.x - B.x) , abs(A.y - B.y)); }

void read()
{
    scanf("%d",&n);
    for(int i=0;i<2*n;i++)
        scanf("%d %d",&m[i].x,&m[i].y);
}

void solve()
{
    for(int mask = 0; mask < (1 << (2*n)); mask++)
    {
        vector<int> bits;
        for(int i=0;i<2*n;i++)
            if((mask >> i)&1)
                bits.pb(i);

        if(bits.size() != n) continue;

        do
        {
            int s = 0;
            s += dist(mp(0,0) , m[ bits[0] ]);
            for(int i=0;i<bits.size() - 1;i++)
                s += dist(m[ bits[i] ] , m[ bits[i + 1] ]);

            if(s < ans) ans = s;
        }
        while(next_permutation(bits.begin() , bits.end()));
    }
    printf("%d\n",ans);
}

int main()
{
    read();
    solve();

    return 0;
}
