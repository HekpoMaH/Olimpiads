#include<cstdio>
using namespace std;
int a[1024][1024],k;
int down(int sum,int i,int j)
{
    int j1;
    for(j1=j;j1<j+k;j1++){sum=sum-a[i-1][j1]+a[i+k-1][j1];}
    return sum;
}
int left(int sum,int i,int j)
{
    int i1;
    for(i1=i;i1<i+k;i1++){sum=sum-a[i1][j+k]+a[i1][j];}
    return sum;
}
int right(int sum,int i,int j)
{
    int i1;
    for(i1=i;i1<i+k;i1++){sum=sum-a[i1][j-1]+a[i1][j+k-1];}
    return sum;
}
int main()
{
    int m,n,i,j,sum=0,maxsum,all=0,ans;
    scanf("%d%d%d",&m,&n,&k);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            all=all+a[i][j];
        }
    }
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            sum=sum+a[i][j];
        }
    }
    maxsum=sum;
    for(i=0;i<=m-k;i++)
    {
        for(j=1;j<=n-k;j++)
        {
            sum=right(sum,i,j);
            if(sum>maxsum){maxsum=sum;}
        }
        if(i>=m-k){break;}
        i++;j--;
        sum=down(sum,i,j);
        if(sum>maxsum){maxsum=sum;}
        for(j=n-k-1;j>=0;j--)
        {
            sum=left(sum,i,j);
            if(sum>maxsum){maxsum=sum;}
        }
        if(i>=m-k){break;}
        i++;j++;
        sum=down(sum,i,j);
        if(sum>maxsum){maxsum=sum;}
    }
    ans=all-maxsum;
    printf("%d\n",ans);
    return 0;
}

/*
3 4 2
1 1 1 2
2 3 4 1
2 1 9 2
*/
