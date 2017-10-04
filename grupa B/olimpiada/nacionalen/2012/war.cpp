#include<iostream>
#include<stack>
#include<cstdio>
#define inf 2000000000
using namespace std;
struct tedge
{
    int to,l,next;
};
struct tindexedvalue
{
    int v,i;
};
int n;
tedge graph[2000009];
int head[1000009],level[1000009];
int parent[1000009];
tindexedvalue min1[1000009],min2[1000009],max1[1000009],max2[1000009];
int solmin[1000009],solmax[1000009];
int indexes[1000009],efp[1000009];
int minfp[1000009],maxfp[1000009];
void read()
{
    int gn=-1;
    int x,y,l;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)head[i]=-1,level[i]=0;
    for(int i=1;i<n;i++)
    {
        //cout<<i<<endl;
        scanf("%d%d%d",&x,&y,&l);
        gn++;
        graph[gn].to=y;
        graph[gn].l=l;
        graph[gn].next=head[x];
        head[x]=gn;
        gn++;
        graph[gn].to=x;
        graph[gn].l=l;
        graph[gn].next=head[y];
        head[y]=gn;
        level[x]++;level[y]++;
    }
}
void dfs(int root)
{
    stack<int> st;
    int c,i,p;
    st.push(root);
    indexes[root]=head[root];
    parent[root]=-1;
    while(!st.empty())
    {
        c=st.top();
        //cout<<c<<endl;
        if(indexes[c]!=-1)
        {
            i=indexes[c];
            if(parent[c]!=graph[i].to)
            {
                parent[graph[i].to]=c;
                efp[graph[i].to]=graph[i].l;
                indexes[graph[i].to]=head[graph[i].to];
                st.push(graph[i].to);
            }indexes[c]=graph[i].next;
        }
        else
        {
            if(parent[c]!=-1)
            {
                if(level[c]==1)
                {
                    min1[c].v=0;
                    max1[c].v=0;
                }
                p=parent[c];
                if(min1[c].v+efp[c]<min1[p].v)
                {
                    min2[p]=min1[p];
                    min1[p].v=min1[c].v+efp[c];
                    min1[p].i=c;
                }
                else if(min1[c].v+efp[c]<min2[p].v)
                {
                    min2[p].v=min1[c].v+efp[c];
                    min2[p].i=c;
                }
                if(max1[c].v+efp[c]>max1[p].v)
                {
                    max2[p]=max1[p];
                    max1[p].v=max1[c].v+efp[c];
                    max1[p].i=c;
                }
                else if(max1[c].v+efp[c]>max2[p].v)
                {
                    max2[p].v=max1[c].v+efp[c];
                    max2[p].i=c;
                }
            }
            st.pop();
        }

    }
}
void dfs2(int root)
{
    int i,c,p;
    stack<int> st;
    st.push(root);
    indexes[root]=head[root];
    minfp[root]=inf;
    maxfp[root]=-inf;
    solmin[root]=min1[root].v;
    solmax[root]=max1[root].v;
    while(!st.empty())
    {
        c=st.top();
        //cout<<c<<endl;
        if(indexes[c]!=-1)
        {
            i=indexes[c];
            if(parent[c]!=graph[i].to)
            {
                if(min1[c].i!=graph[i].to)minfp[graph[i].to]=min(minfp[c],min1[c].v)+graph[i].l;
                else                      minfp[graph[i].to]=min(minfp[c],min2[c].v)+graph[i].l;
                if(max1[c].i!=graph[i].to)maxfp[graph[i].to]=max(maxfp[c],max1[c].v)+graph[i].l;
                else                      maxfp[graph[i].to]=max(maxfp[c],max2[c].v)+graph[i].l;
                solmin[graph[i].to]=min(min1[graph[i].to].v,minfp[graph[i].to]);
                solmax[graph[i].to]=max(max1[graph[i].to].v,maxfp[graph[i].to]);
                indexes[graph[i].to]=head[graph[i].to];
                st.push(graph[i].to);
            }
            indexes[c]=graph[i].next;
        }
        else
        {
            if(parent[c]!=-1)
            {
                if(level[c]==1)
                {
                    solmin[c]=minfp[c];
                    solmax[c]=maxfp[c];
                }
            }st.pop();
        }
    }
}
void solve()
{
    int root;
    tindexedvalue minlost;
    for(int i=1;i<=n;i++)if(level[i]>1){root=i;break;}
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        min1[i].v=inf;
        min2[i].v=inf;max1[i].v=-inf;max2[i].v=-inf;
    }
    dfs(root);dfs2(root);
    minlost.v=inf;
    for(int i=1;i<=n;i++)
    {
        if(solmax[i]-solmin[i]<minlost.v)
        {
            minlost.v=solmax[i]-solmin[i];
            minlost.i=i;
        }
    }
    printf("%d %d\n",minlost.i,minlost.v);
}
int main()
{
    read();
    solve();
}
