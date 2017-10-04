#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
pair<int,int> pp[1000];
int n,tot;
int d=99999,i,j;
int anew(pair<int,int> xx,pair<int,int> yx)
{
    return (xx.first-yx.first)*(xx.first-yx.first)+(xx.second-yx.second)*(xx.second-yx.second);
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)cin>>pp[i].first>>pp[i].second;
    sort(pp+1,pp+n+1);
    for(i=1;i<=n;i++)cout<<pp[i].first<<" "<<pp[i].second<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            ++tot;
            if(pp[j].first-pp[i].first>=d)break;
        }
        d=min(d,anew(pp[i],pp[j]));
        cout<<d<<endl;
    }
    cout<<tot<<endl;
}


