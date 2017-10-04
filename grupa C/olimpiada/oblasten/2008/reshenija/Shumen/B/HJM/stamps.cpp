#include<cstdio>
using namespace std;
int s,n,v[4096],minn[8192];
int main()
{
    int j;
    for(j=0;j<8192;j++)minn[j]=5001;
    scanf("%d%d",&s,&n);
    for(int i=0;i<n;i++)
    scanf("%d",&v[i]);
    minn[1]=1;minn[0]=0;
    for(int i=1;i<=s;i++)
    for(j=0;j<n;j++)
    if(v[j]<=i&&minn[i-v[j]]+1<minn[i])
    minn[i]=minn[i-v[j]]+1;
    printf("%d",minn[s]);
    return 0;
}
