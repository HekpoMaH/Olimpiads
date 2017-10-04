#include<bits/stdc++.h>
using namespace std;
long long a,b,l,r,nod,ans;
int k;
long long getnod(long long x,long long y)
{
    long long r;
    while(y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
vector<long long>v;
set<long long> s;
int main()
{
    freopen ( "game.in" , "r" , stdin ) ;
    freopen ( "game.out" , "w" , stdout ) ;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b;
    cin>>k;
    nod=getnod(a,b);
    /*for(int i=1;i<=)
    long long del=2,br=0;
    //cout<<nod<<endl;
    while(nod!=1)
    {
        if(nod%del==0)nod/=del,br++;
        if(nod%del!=0)
        {
            if(br!=0)v.push_back(make_pair(del,br));
            //cout<<del<<" "<<br<<endl;
            del++;
            br=0;
        }
        //cout<<nod<<" "<<del<<endl;
    }*/
    //cout<<v.size()<<endl;
    //for(int i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second<<"\n";
    //cout<<"-------------------\n";
    long long gorna=min(a,b);
    for(int i=1;i*i<=a;i++)
    {
        if(a%i==0&&b%i==0)
        {
            v.push_back(i);

        }if(i!=a/i){
                if(b%(a/i)==0&&a%(a/i)==0)v.push_back(a/i);
            //if(a%(b/i)==0)v.push_back(b/i);
            }
    }
    long long lef,righ,mid,dolna;
    //if(max(a,b)%min(a,b)==0)v.push_back(min(a,b));
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
    cout<<endl;
    for(int i=1;i<=k;i++)
    {
        //cout<<k<<"\n";
        cin>>l>>r;
        lef=0;righ=v.size()-1;
        while(lef<=righ)
        {
            //cout<<lef<<" "<<righ<<" ";
            mid=(lef+righ)/2;
            //cout<<v[mid]<<" "<<mid<<endl;
            if(v[mid]>r)righ=mid-1;
            if(v[mid]<l)lef=mid+1;
            if(v[mid]>=l&&v[mid]<=r)righ=mid-1,dolna=mid;
        }
        lef=0;righ=v.size()-1;
        while(lef<=righ)
        {
            //cout<<lef<<" "<<righ<<" ";
            mid=(lef+righ)/2;
            //cout<<v[mid]<<" "<<mid<<" "<<l<<" "<<r<<endl;
            if(v[mid]>r)righ=mid-1;
            if(v[mid]<l)lef=mid+1;
            if(v[mid]>=l&&v[mid]<=r)lef=mid+1,gorna=mid;
        }
        //dolna=mid;
        cout<<gorna-dolna+1<<"\n";
    }
}

