/*
TASK:metro
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct metro
{
       vector<int> h;
       vector<long long> st;
};

int m[1024];
metro dp[1024];
int n;

int price(int y,int tmp)
{
    if(y==tmp) return 1;
    if(y<tmp) return 7*(tmp-y);
    if(y>tmp) return (y-tmp)*(y-tmp);
}

int search(vector<int> v,int x)
{
    int l=0,r=v.size()-1,mid;
    while(l<=r)
    {
               mid=(l+r)/2;
               if(v[mid]==x) return mid;
               if(v[mid]>x) r=mid-1;
               else l=mid+1;
    }
    
    return -1;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&m[i]);
    
    for(int i=1;i<=100;i++)
    {
            dp[0].h.push_back(i);
            dp[0].st.push_back( price(m[0],i) );
    }
    
    for(int i=1;i<n;i++)
    {
            for(int j=0;j<dp[i-1].h.size();j++)
            {
                    dp[i].h.push_back( dp[i-1].h[j]+1 );
                    dp[i].h.push_back( dp[i-1].h[j] );
                    dp[i].h.push_back( dp[i-1].h[j]-1 );
                    dp[i].h.push_back( dp[i-1].h[j]-2 );
            }
            sort(dp[i].h.begin(),dp[i].h.end());
            vector<int> v;
            v.push_back(dp[i].h[0]);
            for(int j=1;j<dp[i].h.size();j++)
             if(dp[i].h[j]!=v[v.size()-1]) v.push_back(dp[i].h[j]);
            dp[i].h=v;
            
            for(int j=0;j<dp[i].h.size();j++)
            {
                    vector<long long> all;
                    int pos;
                    pos=search( dp[i-1].h, dp[i].h[j]-1 );
                    if(pos!=-1) all.push_back( dp[i-1].st[pos]+price(m[i],dp[i].h[j]) );
                    
                    pos=search( dp[i-1].h, dp[i].h[j] );
                    if(pos!=-1) all.push_back( dp[i-1].st[pos]+price(m[i],dp[i].h[j]) );
                    
                    pos=search( dp[i-1].h, dp[i].h[j]+1 );
                    if(pos!=-1) all.push_back( dp[i-1].st[pos]+price(m[i],dp[i].h[j]) );
                    
                    pos=search( dp[i-1].h, dp[i].h[j]+2 );
                    if(pos!=-1) all.push_back( dp[i-1].st[pos]+price(m[i],dp[i].h[j]) );
                    
                    sort(all.begin(),all.end());
                    dp[i].st.push_back(all[0]);
            }
    }
    
    long long mn=dp[n-1].st[0];
    for(int i=1;i<dp[n-1].st.size();i++) mn=min(mn, dp[n-1].st[i]);
    
    cout << mn << endl;
    
    return 0;
}
