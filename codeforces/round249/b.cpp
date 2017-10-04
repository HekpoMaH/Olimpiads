#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
using namespace std;
map<pair<string,int>, bool> m;
string a;
int k;
long long ans;
queue<pair<string,int> > q;
void checkcur(pair<string,int> x)
{
    long long xx=0;
    for(int i=0;i<x.first.size();i++)xx=xx*10+x.first[i]-'0';
    ans=max(ans,xx);
}
int main()
{
    cin>>a>>k;
    for(int i=0;i<a.size();i++)
    {
        int mx=a[i],mxi=i;
        for(int j=1;j<=k&&i+j<a.size();j++)
        {
            if(a[i+j]>mx)
            {
                mx=a[i+j];
                mxi=i+j;
            }
        }
        for(int j=mxi-1;j>=i;j--)swap(a[j+1],a[j]);
        k-=mxi-i;
        //cout<<mxi<<" "<<mx-'0'<<" "<<k<<" "<<a<<endl;
    }
    cout<<a<<endl;
}
