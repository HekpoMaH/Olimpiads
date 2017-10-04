#include<iostream>
#include<algorithm>
using namespace std;
int n,s;
pair<int,int> dragon[1004];
int main()
{
    cin>>s>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>dragon[i].first>>dragon[i].second;
    }
    sort(dragon+1,dragon+n+1);
    for(int i=1;i<=n;i++)
    {
        if(s<=dragon[i].first){cout<<"NO"<<endl;return 0;}
        else s+=dragon[i].second;
    }
    cout<<"YES"<<endl;
    return 0;
}