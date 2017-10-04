#include <iostream>
#include <math.h>
#define inf 999999999.0

using namespace std;

double a[501],d[501][501],f[501][501],s[501],topka;
int i,n,p,j,k,l;
int main(){
    cin>>n>>p;
    for(i=1;i<=n;i++)
        for(j=1;j<=p;j++) f[i][j]=inf;
    for(i=1;i<=n;i++){
                      cin>>a[i];
                      s[i]=s[i-1]+a[i];
    }
    for(i=1;i<=n-1;i++){
        for(j=i+1,k=2;j<=n;j++,k++){
            topka=s[j]-s[i-1];
            topka/= k;
            for(l=i;l<=j;l++) d[i][j]+=(topka-a[l])*(topka-a[l]);
        }
    }
    for(i=1;i<=n;i++) f[i][1]=d[1][i];
    for(i=2;i<=p;i++){
        for(j=i+1;j<=n;j++){
            for(k=1;k<j;k++){
                f[j][i]=(f[j-k][i-1]+d[j-k+1][j])>f[j][i]?f[j][i]:(f[j-k][i-1]+d[j-k+1][j]);
            }
        }
    }
    printf("%.4lf\n",f[n][p]);
    return 0;
}
