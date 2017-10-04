#include<bits/stdc++.h>
using namespace std;
long long g[6][6];int a[6];
int n=5;
long long mx=0;
void chek()
{
    long long s=0;
    //if(a[1]!=2)return;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=2)
        {

            if(j+1<=n)s+=g[a[j]][a[j+1]],s+=g[a[j+1]][a[j]];
            //cerr<<a[j] <<" talks with "<<a[j+1]<<" s="<<s<<"\n";
        }
    }
    mx=max(mx,s);
}
int main()
{

    for(int i=1;i<=n;i++)
    {
        a[i]=i;
        for(int j=1;j<=n;j++)cin>>g[i][j];
    }
    do
    {
        chek();//cerr<<"------------\n";
        //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<'\n';

    }while(next_permutation(a+1,a+6));
    cout<<mx<<"\n";
}
