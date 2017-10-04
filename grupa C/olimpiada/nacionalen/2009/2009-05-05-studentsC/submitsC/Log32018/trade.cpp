/*
TASK: trade
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

double eps=1e-3;
int used[100100],n,res;
double a[100200][3],ans[100010],d;
vector<int> v[100050];

int main()
{
    int i;
    double k;
    int k1,k2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%lf",&k1,&k2,&k);
        a[k1][v[k1].size()]=k;
        a[k2][v[k2].size()]=k;
        v[k1].push_back(k2);
        v[k2].push_back(k1);
    }
    k=0.0000;
    res=1;
    used[res]=1;
    while(1)
    {
        if(used[v[res][0]]==0)
        {
            k=a[res][0]-k;
            res=v[res][0];
            used[res]=1;
        }
        else if(used[v[res][1]]==0)
        {
            k=a[res][1]-k;
            res=v[res][1];
            used[res]=1;
        }
        else break;
    }
    k=a[1][1]-k;
    if(n&1)
    {
        ans[1]=k;
        res=1;
        memset(used,0,sizeof(used));
        used[res]=1;
        while(1)
        {
            if(used[v[res][0]]==0)
            {
                ans[v[res][0]]=a[res][0]*2.00-ans[res];
                res=v[res][0];
                used[res]=1;
            }
            else if(used[v[res][1]]==0)
            {
                ans[v[res][1]]=a[res][1]*2.00-ans[res];
                res=v[res][1];
                used[res]=1;
            }
            else break;
        }
        for(i=1;i<n;i++)
         printf("%.2lf ",ans[i]);
        printf("%.2lf\n",ans[i]);
    }
    else
    {
        if(fabs(k)>eps)printf("impossible\n");
        else printf("too many\n");
    }
}
