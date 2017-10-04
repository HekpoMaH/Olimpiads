#include<cstdio>
#include<iostream>
using namespace std;

int a[1024][1024], l[1024][1024], d[1024][1024], k, n;

inline int min(int a, int b) { return (a<b?a:b); }
void chang(int rd, int sb) //check angle
{
    int res=a[rd][sb], t;
    l[rd][sb]=l[rd][sb+1]+a[rd][sb+1]-a[rd][sb+k+1];
    d[rd][sb]=d[rd+1][sb]+a[rd+1][sb]-a[rd+k+1][sb];
}

int main()
{
    int i, j;
    scanf("%d%d", &n, &k);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", a[i]+j);
            //a[i][j]=rand()%2000 - 1000; - testgen
    int max=-2000000000;
    for(i=n; i>0; i--)
        for(j=n; j>=1; j--)
        {
            chang(i,j);
            if(l[i][j]+d[i][j]+a[i][j]>max)
                max=a[i][j]+l[i][j]+d[i][j];
        }
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(a[i][j]+l[i][j]+d[i][j]==max)
                printf("%d %d\n", i, j);
    return 0;
}
