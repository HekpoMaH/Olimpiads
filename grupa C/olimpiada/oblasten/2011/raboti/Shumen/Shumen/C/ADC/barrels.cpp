#include<cstdio>
using namespace std;
int n,s,a[1024],mb;
void read()
{
    int i;
    scanf("%d%d",&s,&n);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
}
void rec(int ss,int br)
{
    int i;
    if(ss==0)
    {
        if(mb>br)mb=br;
        return;
    }
    for(i=1;i<=n;i++)
    if(ss-a[i]>=0)rec(ss-a[i],br+1);
}
int main()
{
    read();
    rec(s,0);
    printf("%d\n",mb);
    return 0;
}
