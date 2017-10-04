#include<iostream>
using namespace std;
int used[100000],t,s,br;
int n,p[100000];
int pos;
int main()
{
    cin>>n>>s>>t;
    for(int i=1;i<=n;i++)cin>>p[i];
    pos=s;
    while(used[pos]==0&&pos!=t)
    {
        used[pos]=1;
        pos=p[pos];
        br++;
    }
    if(used[pos]==1)cout<<-1<<endl;
    else cout<<br<<endl;
}
