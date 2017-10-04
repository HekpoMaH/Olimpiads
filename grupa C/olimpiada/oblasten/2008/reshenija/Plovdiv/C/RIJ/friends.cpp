#include<cstdio>
using namespace std;
int used[2002],mats[2002][2002],n,m;
int bfs()
{
    int query[4096],k=2,max=-1,tmp;
    query[0]=1;
    query[1]=-1;
    tmp=0;
    for(int i=0;i<k;i++)
    {     
        if(query[i]==-1)
        {
            if(tmp>max) max=tmp;
            tmp=0;
            if(query[k-1]!=-1)
            {
                query[k]=-1;
                k++;
            }
            continue;
        }
        used[query[i]]=1;
        tmp++;
        for(int j=1;j<=n;j++)
        if((mats[query[i]][j]==1)&&(used[j]==0))
        {
            used[j]=1;
            query[k]=j;
            k++;
        }
    }
    return max;
}
int main()
{
    int a,b,ret;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        mats[a][b]=1;
        mats[b][a]=1;
    }
    ret=bfs();
    printf("%d\n",ret);
    return 0;
}
