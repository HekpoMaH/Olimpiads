#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int used[15],a[15],b[15],ans,res[15];
int n,tmp;

void rec(int k)
{
    int i;
    if(k>n){if(tmp<ans||ans==0)ans=tmp;return;}
    if(tmp>ans&&ans)return;
    for(i=1;i<=2*n;i++)
    {
        if(used[i]==0)
        {
            used[i]=1;
            res[k]=i;
            tmp+=max((int)fabs((double)(a[res[k]]-a[res[k-1]])),(int)fabs((double)(b[res[k]]-b[res[k-1]])));
            rec(k+1);
            tmp-=max((int)fabs((double)(a[res[k]]-a[res[k-1]])),(int)fabs((double)(b[res[k]]-b[res[k-1]])));
            used[i]=0;
        }
    }
}

int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=2*n;i++)
     scanf("%d%d",&a[i],&b[i]);
    rec(1);
    printf("%d\n",ans);
}
