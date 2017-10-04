#include<iostream>
using namespace std;
struct graph
{
    int v[4],brv;
    double srv[4];
};
graph gr[100001];
int n,x,y,qb,qe,queue[100001],used[100001];
double z,a[100001];
int main()
{
    for(int i=1;i<=n;i++)gr[i].brv=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>z;
        gr[x].brv++;
        gr[x].v[gr[x].brv]=y;
        gr[x].srv[gr[x].brv]=z;
        gr[y].brv++;
        gr[y].v[gr[x].brv]=x;
        gr[y].srv[gr[x].brv]=z;
    }
    queue[0]=gr[1].v[1];used[gr[1].v[1]]=1;
    a[gr[1].v[1]]=gr[1].srv[1];
    qb=qe=1;
    queue[1]=1;used[1]=1;
    while(qb<=qe)
    {
        x=queue[qb];qb++;
        y=gr[x].v[1];
        if(used[y]==0)
        {
            qe++;
            queue[qe]=y;
            used[y]=1;
            a[x]=gr[x].srv[1];
        }
        y=gr[x].v[2];
        if(used[y]==0)
        {
            qe++;
            queue[qe]=y;
            used[y]=1;
            a[x]=gr[x].srv[2];
        }
    }
    y=queue[qe];
    if(gr[y].v[1]==queue[qe-1])a[y]=gr[y].srv[2];
    else a[y]=gr[y].srv[1];
    for(int i=0;i<=qe;i++)
    {
        cout<<"vrah="<<queue[i]<<" "<<"a="<<a[queue[i]]<<endl;
    }
}