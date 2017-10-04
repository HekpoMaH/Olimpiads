#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int> > a;
int n,x,mx,br;
bool cmp(pair<int,int>x, pair<int,int>y)
{
    if(x.first<y.first)return true;
    if(x.first==y.first&&x.second<y.second)return true;
    return false;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(pair<int,int>(x,1));
        cin>>x;
        a.push_back(pair<int,int>(x,-1));
    }
    sort(a.begin(),a.end(),cmp);
    //for(auto x: a)cout<<x.first<<" "<<x.second<<endl;
    int k=0;
    for(auto x: a)
    {
        k+=x.second;
        if(k>mx)mx=k;
    }
    //cout<<mx<<endl;
    k=0;
    int p,v=a[0].first-1;
    for(auto x: a)
    {
        if(x.second==1)
        {
            k+=x.second;
            if(k==mx)
            {
                p=x.first;
                if(p==v)br--;
            }
        }
        else
        {
            if(k==mx)
            {
                v=x.first;br+=v-p+1;
            }
            k+=x.second;
        }
        
    }
    cout<<br<<endl;
    return 0;
}
