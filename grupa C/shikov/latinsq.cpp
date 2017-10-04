#include<iostream>
#include<vector>
using namespace std;
struct sets
{
    vector<int> v[500];
};
sets inp;
vector<int>news;
int m,n,x;
int erepr[500];
int srepr[500];
int elqueue[500];
int front=0,endd=0;
int inqueuefromset[500];
void solve(sets given)
{
    int p=0,f=0;
    bool frep,fnewrep;
    int u=0,s=0,w=0;
    for(int i=1;i<=n;i++)erepr[i]=0;
    for(int i=1;i<=n;i++)srepr[i]=0;
    for(int i=1;i<=n;i++)
    {
        frep=false;
        for(int j=1;j<=m;j++)
        {
            if(erepr[given.v[i][j]]==0)
            {
                erepr[given.v[i][j]]=i;
                srepr[i]=given.v[i][j];
                frep=true;
                break;
            }
        }
        if(frep==false)
        {
            for(int j=1;j<=n;j++)inqueuefromset[j]=0;
            for(int j=1;j<=given.v[i].size();j++)
            {
                elqueue[j]=given.v[i][j];
                inqueuefromset[given.v[i][j]]=j;
            }
            front=1;endd=given.v[i].size();
            fnewrep=false;
            while(fnewrep==false&&front<=endd)
            {
                u=elqueue[front];
                front++;
                s=erepr[u];
                p=given.v[s].size();
                for(int j=1;j<=p;j++)
                {
                    f=given.v[s][j];
                    if(erepr[f]==0)
                    {
                        fnewrep=true;
                        while(s<i)
                        {
                            w=erepr[s];
                            erepr[f]=s;
                            srepr[s]=f;
                            s=inqueuefromset[w];
                            f=w;
                        }
                        erepr[f]=i;
                        srepr[i]=f;
                        break;
                    }
                    else if(inqueuefromset[f]==0)
                    {
                        endd++;
                        elqueue[endd]=f;
                        inqueuefromset[f]=s;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)inp.v[m+1].push_back(srepr[i]);
    m++;
}
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            inp.v[j].push_back(x);
        }
    }
    solve(inp);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<inp.v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
2 5
3 1 5 2 4
2 5 4 3 1
*/
