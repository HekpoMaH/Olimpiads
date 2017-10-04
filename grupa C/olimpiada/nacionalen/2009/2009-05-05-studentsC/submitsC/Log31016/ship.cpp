/*
TASK: ship
LANG: C++
*/

#include<cstdio>
#include<queue>
#define MAXN 10000
int n,w,sum;
int t[MAXN],p[MAXN];
std::queue<int> q;
void rep(int a,int b)
{
    sum+=t[a]+t[b];
    int k=p[a];
    p[a]=p[b];
    p[b]=k;
    k=t[a];
    t[a]=t[b];
    t[b]=k;
}
int work()
{
    return w=q.empty()?n:q.front();
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&t[i]);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        if(p[i]!=i)
            q.push(i);
    }
    while(work()<n)
    {
        q.pop();
        if(p[w]!=w)
            rep(w,p[w]);
    }
    printf("%d\n",sum);
    return 0;
}
