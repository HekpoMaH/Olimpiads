#include<iostream>
#include<cmath>
using namespace std;
int n,m,d;
long long a[102][102];
long long dd[10002],s,s2,mn=1000000099LL,kr,ada[10009];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>d;
    if(n==1&&m==1){cout<<0<<endl;return 0;}
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){cin>>a[i][j];s2=max(s2,a[i][j]);kr=a[i][j]%d;ada[kr]++;dd[a[i][j]]++;}
    }
    if(ada[kr]!=n*m){cout<<-1<<endl;return 0;}
    //for(int i=1;i<=10000;i++)s+=dd[i];
    for(int i=kr;i<=s2;i+=d)
    {
        //cout<<i<<" ";
        for(int j=1;j<=s2;j++)
        {
            s+=abs(i-j)/d*dd[j];
        }
        //cout<<s<<endl;
        mn=min(mn,s);
        s=0;
    }
    cout<<mn<<endl;
}
