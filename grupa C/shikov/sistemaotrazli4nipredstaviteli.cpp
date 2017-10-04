#include<iostream>
using namespace std;
int sets[1024][1024];
int erepr[1024];
int srepr[1024];
int elqueue[1024];
int front=0,endd=0;
int inqueuefromset[1024],n,m;
void input()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>sets[i][0];
        for(int j=1;j<=sets[i][0];j++)cin>>sets[i][j];
    }
}
int u,s,p,v,w;
int main()
{
    bool frep,fnewrep;
    input();
    for(int i=1;i<=n;i++)erepr[i]=0;
    for(int i=1;i<=m;i++)srepr[i]=0;
    for(int i=1;i<=m;i++)
    {
        frep=false;
        for(int j=1;j<=sets[i][0];j++)
        {
            if(erepr[sets[i][j]]==0)
            {
                erepr[sets[i][j]]=i;
                srepr[i]=sets[i][j];
                frep=true;
                break;
            }
        }
        if(frep==false)
        {
            for(int j=1;j<=n;j++)inqueuefromset[j]=0;
            for(int j=1;j<=sets[i][0];j++)
            {
                elqueue[j]=sets[i][j];
                inqueuefromset[sets[i][j]]=i;
            }
            front=1;endd=sets[i][0];
            fnewrep=false;
            while(fnewrep==false&&front<=endd)
            {
                u=elqueue[front];
                front++;
                s=erepr[u];//nomer na mnojestvo
                p=sets[s][0];
                for(int j=1;j<=p;j++)
                {
                    v=sets[s][j];
                    if(erepr[v]==0)
                    {
                        fnewrep=true;
                        while(s<i)
                        {
                            w=erepr[s];
                            erepr[v]=s;
                            srepr[s]=v;
                            s=inqueuefromset[w];
                            v=w;
                        }
                        erepr[v]=i;
                        srepr[i]=v;
                        break;
                    }
                    else if(inqueuefromset[v]==0)
                    {
                        endd++;
                        elqueue[endd]=v;
                        inqueuefromset[v]=s;
                    }
                }
            }
            if(fnewrep==false)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<srepr[i]<<" ";
    cout<<endl;
    return 0;
}