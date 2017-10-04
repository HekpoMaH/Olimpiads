#include<cstdio>
using namespace std;
int mat[1002][1002];
int rows[1002][1002];
int cols[1002][1002];
int main()
{
    int a,n,k,ki,kj,tmp,maxi=-2000000,mxi,mxj;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        scanf("%d",&a);
        mat[i][j]=a;
        if(j==0) rows[i][j]=a;
        else rows[i][j]=rows[i][j-1]+a;
        if(i==0) cols[j][i]=a;
        else cols[j][i]=cols[j][i-1]+a;
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        if(k<n-1-i)
        ki=k;else ki=n-1-i;
        if(k<n-1-j)
        kj=k;else kj=n-1-j;
        tmp=rows[i][j+kj]-rows[i][j];
        tmp+=(cols[j][i+ki]-cols[j][i]);
        tmp+=mat[i][j];
        if (tmp>maxi)
        {
            maxi=tmp;
            mxi=i+1;
            mxj=j+1;
        }
    }
    printf("%d %d\n",mxi,mxj);
    return 0;
}
