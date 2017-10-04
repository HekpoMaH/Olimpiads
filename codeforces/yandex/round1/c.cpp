#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
long long t;
long long nn;
long long kk;
set<pair<int,int> >s;
int x;
void solve(long long n,long long k)
{
    srand(time(NULL));
    vector<long long>v;long long i=2;
    while(i<=n)
    {
        cout<<i<<" "<<n<<endl;
        //cout<<(long long)(sqrt(i))<<" "<<(double)(sqrt(i))<<endl;
        if(!(n%i==0&&(long long)(sqrt(i))!=(double)(sqrt(i))))i++;
        if(n%i==0&&(long long)(sqrt(i))!=(double)(sqrt(i)))v.push_back(i),n/=i,cout<<i<<endl;

        if(v.size()==k&&n==1){cout<<"YES"<<endl;return;}
    }
    //cout<<v.size()<<endl;
    if(v.size()==k){cout<<"YES"<<endl;return;}
    cout<<"NO"<<endl;
}
int main()
{
    set<pair<int,int> >::iterator it;
    for(int i=1;i<=1000000000;i++)
    if((long long)(sqrt(i))!=(double)(sqrt(i)))s.insert(make_pair(i,1));
    for(it=s.begin();it!=s.end();it++)
    {
        int x=2;
        while(x*((*it).first)<=1000000000&&(*it).second<50)
        {
            if((long long)(sqrt(x))!=(double)(sqrt(x)))s.insert(make_pair(x*(*it).first,(*it).second+1));
            x++;
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>nn>>kk;
        solve(nn,kk);
    }
}
