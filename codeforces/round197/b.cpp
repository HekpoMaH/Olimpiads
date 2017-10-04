#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100009];
long long br;
long long wtf[100009],lastpos[100009],mx;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
        if(a[i]<a[i-1]){br++;}
        lastpos[a[i]]=i;
    }
    cout<<(long long)((br)*n+a[m]-1)<<endl;
}

