#include<iostream>
using namespace std;
pair<long long,long long>pr[8003];
int n,mn,sum,mxs;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>pr[i].first>>pr[i].second;
    for(int i=0;i<n;i++)
    {
        mn=pr[i].second;
        sum=pr[i].first;
        if(mn*sum>mxs)mxs=mn*sum;
        for(int j=i+1;j<n;j++)
        {
            if(pr[j].second<mn)mn=pr[j].second;
            sum+=pr[j].first;
            if(mn*sum>mxs)mxs=mn*sum;
        }
    }
    cout<<mxs<<endl;
    return 0;
}