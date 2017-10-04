/*
TASK:ship
LANG:C++
*/
#include<cstdio>
using namespace std;
bool used[10100];
int num[10100];
int pos[10100];
int d[10100];
int n;
int main()
{
    int r=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&num[i]);
    for(int i=0;i<n;i++)
    scanf("%d",&pos[i]);
    int x=n,f,br;
    for(int i=0;i<n;i++)
    if(!used[i])
    {
        x=i;br=0;
        while(!used[x])
        {
            d[br++]=x;
            used[x]=1;
            x=pos[x];
        }
      //  for(int i=0;i<br;i++)
    //    printf("%d ",d[i]
        x=0;f=0;
        for(int i=0;i<br-1;i++)
        {   
            f+=num[d[i]];
            if(num[d[i]]+num[d[i+1]]>x)x=num[d[i]]+num[d[i+1]];
        }
        f+=num[d[br-1]];
        if(num[d[br-1]]+num[d[0]]>x)x=num[d[br-1]]+num[d[0]];
        r+=f*2-x;
    }
    printf("%d\n",r);
    return 0;
}
