#include<iostream>
#include<cstring>
using namespace std;
int a[100004],b[100004],s[100004];
int n,k;
int used[100004];
int br=0;
int findbig()
{
    for(int i=n;i>=1;i--)
    {
        if(used[i]==0){used[i]=1;return a[i];}
    }
}
int findsmallx()
{
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0&&a[i]+b[br-1]>k){used[i]=1;return a[i];}
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0){used[i]=1;return a[i];}
    }
}
int findsmall()
{
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0){used[i]=1;return a[i];}
    }
}
int findbigx()
{
    for(int i=n;i>=1;i--)
    {
        if(used[i]==0&&a[i]+s[br-1]>k){used[i]=1;return a[i];}
    }
    for(int i=n;i>=1;i--)
    {
        if(used[i]==0){used[i]=1;return a[i];}
    }
}
void makebig()
{
    memset(used,0,sizeof(used));
    br=0;
    br++;
    b[br]=findbig();
    do
    {
        br++;
        if(br%2==0)b[br]=findsmallx();
        if(br%2==1)b[br]=findbig();
    }while(br!=n);
    for(int i=1;i<=n;i++)cout<<b[i]<<" ";
    cout<<endl;
}
void makesmall()
{
    memset(used,0,sizeof(used));
    br=0;
    br++;
    s[br]=findsmall();
    do
    {
        br++;
        if(br%2==0)b[br]=findbigx();
        if(br%2==1)b[br]=findsmall();
    }while(br!=n);
    for(int i=1;i<=n;i++)cout<<s[i]<<" ";
    cout<<endl;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    makebig();makesmall();
}
