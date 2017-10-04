#include<iostream>
using namespace std;
int n,mnx=999999,id,mxy,ms=-1;
int ans[100005][3],br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ans[i][1]>>ans[i][2];
        if(ans[i][2]-ans[i][1]>ms)ms=ans[i][2]-ans[i][1],id=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(id!=i&&!(ans[id][1]<=ans[i][1]&&ans[id][2]>=ans[i][2])){cout<<-1<<endl;return 0;}
    }
    cout<<id<<endl;
}

