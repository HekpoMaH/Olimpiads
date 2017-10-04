#include<bits/stdc++.h>
using namespace std;
const int maxn=255;
vector<bitset<maxn> >a(maxn,0);
int n;
bitset<maxn> sol()
{
    for(int i=0;i<n;i++)a[i][n]=1;
    for(int c=0;c<n;c++)
    {
        for(int i=c;i<=n;i++)if(a[i][c])
        {
            swap(a[i],a[c]);
            break;
        }
        if(a[c][c]==0)return 0;
        for(int i=0;i<n;i++)if(i!=c&&a[i][c])a[i]^=a[c];
    }
    bitset<maxn> re=0;
    for(int i=0;i<n;i++)re[i]= a[i][n]==1;
    return re;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        while(1)
        {
            cin>>t;
            if(t==-1)break;
            a[t-1][i]=1;
        }
    }
    bitset<maxn> ans=sol();
    if(ans==0)
    {
        cout<<"No solution\n";
        exit(0);
    }
    for(int i=0;i<n;i++)if(ans[i])cout<<i+1<<" ";
    cout<<endl;
}
