#include<bits/stdc++.h>
using namespace std;
int n,m,t,x,y,br,gn;
pair<int,int> ap[5];
int main()
{
    cin>>n>>m>>t;
    while(cin>>x)
    {
        cin>>y;
        //cout<<"x="<<x<<" "<<"y="<<y<<endl;
        ap[++br].first=x;
        ap[br].second=y;
    }
    //cout<<ap[1].first<<" "<<ap[1].second<<endl;
    //cout<<ap[2].first<<" "<<ap[2].second<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int l=1;
            for(int k=1;k<=br;k++)
            {
                if(abs(ap[k].first-i)+abs(ap[k].second-j)<=t){l=0;break;}
            }
            gn+=l;
        }
    }
    cout<<gn<<endl;
}
