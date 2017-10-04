#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int m,n,r,k,i,j,l=0,x,y,t,sum=0;
    scanf("%d%d%d%d",&m,&n,&r,&k);
    r--;
    x=r/n;
    y=r%n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            l++;
            t=(abs(j-y)+abs(i-x));
            if((t<=k)&&(t%2==k%2)){sum=sum+l;}
        }
    }
    printf("%d\n",sum);
    return 0;
}
