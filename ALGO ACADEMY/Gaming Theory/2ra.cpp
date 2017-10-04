//http://goml.at/index.php?id=3331
#include<bits/stdc++.h>
using namespace std;
int n,p,m;
int mx,mnms;
int sum,a[100],br0;
int a1=1000000000,a2;
set<int> msng;
int main()
{
    cin>>n;for(int i=1;i<=n;i++)msng.insert(i);
    for(int i=1;i<=n;i++)
    {

        sum+=i,cin>>a[i],mx=max(mx,a[i]);
        if(a[i]!=0)sum-=a[i],msng.erase(a[i]);
        else br0++;
    }
    set<int>::iterator it;
    //it=msng.begin();
    //mx=max(mx,*it);
    cin>>p>>m;
    if(mx!=0)
    {
        a1=p/mx+min(p%mx,1);
    }

    //cout<<"R"<<endl;
    a2=(p/sum)*br0;
    if(p%sum!=0)
    {
        int rest=p-sum*a2/br0;
        //cout<<sum<<" "<<p<<" "<<rest<<endl;
        for(it=msng.begin();it!=msng.end();it++)
        {
            if(rest<=0)break;
            rest-=*it;
            a2++;
        }
    }
    int ans=min(a1,a2);
    if(ans<=m)
    {
        cout<<"Success!\n";
        cout<<ans<<endl;
    }
    else
    {
        cout<<"Fail!\n";
        cout<<ans-m<<endl;
    }
}
/*
4
1 0 0 0
120
for 3 turns- max(1,9)->9
120/9=13
13*3 turns=39 turns. sum up to now is 13*9=117

*/
