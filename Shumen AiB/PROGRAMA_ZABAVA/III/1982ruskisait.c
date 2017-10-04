#include<iostream>
using namespace std;
int n,m;
int a[102],b[102];
int used[1000003];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i];
        b[i]+=a[i]*100;
    }
    used[0]=1;
    for(int i=0;i<=1000000;i++)
    {
        if(used[i]!=0)
        {
            for(int i=1;i<=m;i++)used[i+b[i]]=1;
        }
    }
    for(int i=0;i<=20;i++)cout<<used[i]<<" ";
    cout<<endl;
}