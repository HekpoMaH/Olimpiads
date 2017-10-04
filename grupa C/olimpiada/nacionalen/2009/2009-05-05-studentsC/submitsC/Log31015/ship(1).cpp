/*
TASK: ship
LANG: C++
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
priority_queue<long> a;
vector<long> b;
vector<pair<long, long> > c;
long n,x,y,i,j,sum,z[100001],l;
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)
    {
             cin>>x;
             c.push_back(make_pair(x,i-1));
             if(z[x]==0) a.push(x);
             z[x]=1;
    }
    for(i=1; i<=n; i++)
    {
             cin>>x;
             b.push_back(x);
    }
    long m=a.size();
    while(!a.empty())
    {
             for(j=0; j<=n-1; j++)
             {
                      if(c[j].first==a.top()) {if(c[j].second!=b[j]) {for(l=0; l<=n-1; l++)
                      {
                        if(b[l]==c[j].second) {swap(c[j],c[l]); sum+=c[j].first+c[l].first; break;}
                      }}}
             }
             a.pop();
    }
    cout<<sum<<endl;
    //system ("pause");
    return 0;
}
