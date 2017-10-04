#include<iostream>
#include<cstdio>
using namespace std;
int sp[5004],n,a,b,p,q,s,pr=0;
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    sp[0]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&p,&q,&s);
        for(int j=p;j<=q;j++)sp[j]=s;
    }
    for(int i=a;i<=b;i++)
    {
        if(sp[i-1]!=sp[i])pr+=sp[i];
    }
    printf("%d",pr);
    return 0;
}
