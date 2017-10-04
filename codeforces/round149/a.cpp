#include<iostream>
using namespace std;
int x,y,a,b;
int ans[10000][2],br;
int main()
{
    cin>>x>>y>>a>>b;
    for(int i=a;i<=x;i++)
    {
        for(int j=b;j<=y;j++)
        {
            if(i>j)br++,ans[br][1]=i,ans[br][2]=j;
        }
    }
    cout<<br<<endl;
    for(int i=1;i<=br;i++)
    {
        cout<<ans[i][1]<<" "<<ans[i][2]<<endl;
    }
}
