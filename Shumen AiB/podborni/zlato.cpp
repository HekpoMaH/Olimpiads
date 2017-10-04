#include<bits/stdc++.h>
using namespace std;
unsigned long long k,t,s,n;
unsigned long long mini=1,gold;
vector<pair<int,int> > wbb;// will be built
int main()
{
    cin>>k>>t>>s>>n;
    int uk1=0;
    for(unsigned long long i=1;i<=n;i++)
    {
        //cout<<i<<" "<<gold<<endl;
        while(wbb.size()!=0&&uk1<wbb.size()&&wbb[uk1].first<=i)
        {
            //cout<<"->"<<wbb[uk1]
            if(wbb[uk1].first==i)mini+=wbb[uk1].second;
            uk1++;
        }
        //cout<<"abd"<<" "<<mini<<endl;
        unsigned long long br=0,mbr=0;
        unsigned long long l=0,r=gold/s;
        while(l<=r)
        {
            br=(l+r)/2;
            if((unsigned long long)((unsigned long long)(n-(i+t))*br*k)<br*s)r=br-1;
            else mbr=max(br,mbr),l=br+1;

        }
        if(mbr!=0)wbb.push_back(make_pair(i+t+1,mbr));
        gold+=mini*k;
    }
    cout<<gold<<endl;
}
