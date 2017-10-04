#include <stdio.h>

#define maxN 512

int n,p;
double A[maxN];
double F[maxN][maxN];
double sumA[maxN], sumA2[maxN];
double S;

void input()
{
     int i;
     scanf("%d%d",&n,&p);
     for (i=1;i<=n;++i) scanf("%lf",&A[i]);
     for (i=1;i<=n;++i) {
         sumA[i] = sumA[i-1] + A[i];
         sumA2[i] = sumA2[i-1] + A[i]*A[i];
         }
}

double D(int a, int b)
{
       S = (double)(sumA[b]-sumA[a-1])/(b-a+1);
       return (double)(b-a+1)*S*S - 2.0*S*(sumA[b]-sumA[a-1]) + (double)sumA2[b]-sumA2[a-1];
}

void solve()
{
     int i,j,k;
     for (i=1;i<=n;++i) F[i][1] = D(1,i);
     for (i=1;i<=n;++i)
         for (j=2;j<=i && j<=p;++j) {
             F[i][j] = F[i-1][j-1]+D(i,i);
             for (k=1;k<i;++k)
                 if (F[i-k][j-1]+D(i-k+1,i) < F[i][j]) F[i][j] = F[i-k][j-1]+D(i-k+1,i);
             }
     printf("%.4lf\n",F[n][p]);
}

int main()
{
    input();
    solve();
    return 0;
}
