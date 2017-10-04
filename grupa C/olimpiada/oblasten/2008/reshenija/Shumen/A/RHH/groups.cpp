#include <cstdio>

const int MAXN = 512;

int n , k;
double a[MAXN];
double dp[MAXN][MAXN];
double d[MAXN][MAXN];

void read() {
    scanf ("%d%d",&n,&k);
    int i;
    
    for (i=1;i<=n;i++)
        scanf ("%lf",&a[i]);
}

void solve() {
    int i , j , t;
    double cur , sum;
    int end;
    
    for (i=1;i<=n;i++)
        for (j=i;j<=n;j++) {
            cur = sum = 0;
            
            for (t=i;t<=j;t++)
                cur += a[t];
            cur /= (double)(j-i+1);
            
            for (t=i;t<=j;t++)
                sum += (a[t]-cur)*(a[t]-cur);
            
            d[i][j] = d[j][i] = sum;
        }
    
    dp[1][1] = d[1][1];
    for (i=2;i<=n;i++) {
        dp[i][1] = d[1][i];
        for (j=2;j<=((i<k)?i:k);j++) {
            dp[i][j] = 1e100;
            for (t=i-1;t>=1;t--)
                if ( dp[t][j-1] + d[t+1][i] < dp[i][j] )
                  dp[i][j] = dp[t][j-1] + d[t+1][i];
                else    
                    if ( d[t+1][i] > dp[i][j] ) break;
        }
    }
    
    printf ("%.4lf\n",dp[n][k]);
}

int main() {
    read();
    solve();
    
    return 0;    
}
