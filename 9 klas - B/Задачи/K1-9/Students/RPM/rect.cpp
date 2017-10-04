#include <iostream>
using namespace std;
int main()
{
    int a[512][512];
    int i,j,k,c,d,p,q;
    int n;
    int br=0;
    int maxi=0,maxj=0;
    scanf("%d",&n);
    for (i=0;i<512;i++)
        for (j=0;j<512;j++) a[i][j]=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&c,&d,&p,&q);
        if(p>maxi)maxi=p;
        if(q>maxj)maxj=q;
        for (j=c;j<p;j++)
            for (k=d;k<q;k++)
                a[j+1][k+1]+=i;
    }
    for (i=0;i<=maxi+1;i++)
        for (j=0;j<=maxj+1;j++)
        {
            if (a[i-1][j]<a[i][j]) br++;
            if (a[i+1][j]<a[i][j]) br++;
            if (a[i][j-1]<a[i][j]) br++;
            if (a[i][j+1]<a[i][j]) br++;
        }
    printf("%d\n",br);
return 0;
}

    
                
