#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int> p[1004];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].second>>p[i].first;
    }
    sort(p+1,p+n+1);
    long long cnt=1,i=1,pts=0;
    while(cnt!=0&&n>0)
    {
        cnt+=p[n].first;
        pts+=p[n].second;
        //cout<<cnt<<endl;
        n--;cnt--;
    }
    cout<<pts<<endl;
    return 0;
}