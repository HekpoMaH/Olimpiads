#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool x[20000000];
int n,q;
struct pl
{
    int id,idp,sum,red;
};
pl plo[20000];
bool used[20000];
void dfs(int vrah)
{
    used[vrah]=true;
    stack<pl> s;
    pl c,nn;
    s.push(plo[vrah]);cout<<"WTF"<<endl;
    while(!s.empty())
    {
        c=s.top();
        s.pop();
        x[c.sum]=true;
        for(int i=1;i<=n;i++)
        {
            if(used[i]==false)
            {
                nn=plo[i];
                if(nn.idp==c.red)
                {
                    nn.sum=c.sum+plo[i].id;
                    used[i]=true;
                    s.push(nn);
                }
            }
        }
    }
}
int main()
{
    
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>plo[i].id>>plo[i].idp;
        plo[i].sum=0;plo[i].red=i-1;
    }
    for(int i=1;i<=n;i++)
    {
        if(plo[i].idp==-1){memset(used,false,sizeof(used));dfs(i);}
    }
    int mxi=0,sth;
    for(int i=1;i<=q;i++)
    {
        cin>>sth;mxi=0;
        for(int i=1;i<=sth;i++)if(x[i]==true)mxi=i;
        cout<<mxi<<endl;
    }
    return 0;
}