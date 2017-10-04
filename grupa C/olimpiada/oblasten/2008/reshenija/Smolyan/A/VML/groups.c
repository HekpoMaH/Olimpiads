#include <stdio.h>
#define MAXN 524
#define max(a, b) ((a>b)?(a):(b))
#define min(a, b) ((a<b)?(a):(b))
#define INF 1<<29

int N, P;
double pt[MAXN];
double s[MAXN][MAXN];
double d[MAXN][MAXN];
double din[MAXN][MAXN];

double gr(int st, int into)
{
    int i;
    double get, ret;
    if(din[st][into] != -1)
        return din[st][into];
    if(into <= 0 || st>=N)
        return -1;
    if(into == 1)
        return d[st][N-1];
    
    ret = INF;
    for(i=st+1; i<N; i++)
    {
        get = gr(i, into-1);
        if(get!=-1)
            ret = min(ret, d[st][i-1] + get);
    }
    din[st][into] = ret;
    return ret;
}

main()
{
    int i, y, z;
    double cur;
    scanf("%d %d", &N, &P);
    for(i=0; i<N; i++)
        scanf("%lf", &pt[i]);
    
    for(i=0; i<N; i++)
        for(y=0; y<N; y++)
            din[i][y] = -1;
    
    for(i=0; i<N; i++)
    {
        cur = 0;
        for(y=i; y<N; y++)
        {
            cur+=pt[y];
            s[i][y] = cur/(y-i+1);
        }
    }
    
    for(i=0; i<N; i++)
        for(y=i; y<N; y++)
        {
            d[i][y]=0;
            for(z=i; z<=y; z++)
                d[i][y] += (pt[z] - s[i][y])*(pt[z] - s[i][y]);
        }
    
    
    printf("%.4lf\n", gr(0, P));
    return 0;
}
