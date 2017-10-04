#include<bits/stdc++.h>
using namespace std;
int brx[109];
int bry[109];
int main()
{
    int n,x,y;
    int i;
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        brx[x]++;
        bry[y]++;
    }
    int br1=0,br2=0;
    for(int i=0;i<=100;i++)
    {
        if(brx[i]>0)br1++;
        if(bry[i]>0)br2++;
    }
    cout<<min(br1,br2)<<endl;
}
