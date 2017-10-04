#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,k;
int a[100006],in1,in2=100005;
void check(int f,int l)
{
    bool test[13005];
    for(int i=1;i<=k;i++)test[i]=false;
    for(int i=f;i<=l;i++)test[a[i]]=true;
    //cout<<f<<" "<<l<<endl;
    //for(int i=1;i<=k;i++)cout<<test[a[i]]<<" ";
    //cout<<endl;
    bool fl=true;
    for(int i=1;i<=k;i++)
    {
        if(test[i]==false)
        {
            fl=false;
            break;
        }
    }
    if(fl==true)in1=f,in2=l;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(j-i+1<in2-in1+1)check(i,j);
        }
    }
    cout<<in1<<" "<<in2<<endl;
    return 0;
}