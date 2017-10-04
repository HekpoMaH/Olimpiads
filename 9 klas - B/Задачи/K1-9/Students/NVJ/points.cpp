#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,k,i;
    cin>>n>>k;
    vector<long long> d(n+3,0);
    d[1]=1ll;
    d[2]=1ll;
    int j;
    for(i=3;i<=n;i++)
    {
     if(i>k)
      for(j=i-1;j>=i-k;j--)
       d[i]+=d[j];
     else
      for(j=i-1;j>0;j--)
       d[i]+=d[j];
    }
    cout<<d[n]<<endl;
    return 0;
}
