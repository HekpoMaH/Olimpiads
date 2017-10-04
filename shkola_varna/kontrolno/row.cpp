#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
priority_queue<pair<long long,int> > pq;
int a[1009];
int n,k,index;long long pr=-42,top;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    int i,j;
    for(i=1;i<=k;i++)cin>>a[i],pq.push(make_pair(-a[i],i));
    //sort(a+1,a+k+1);
    i=1;
    while(i<=n)
    {
        top=-pq.top().first;
        index=pq.top().second;
        pq.pop();
        if(pr==top)continue;
        else pr=top;

        i++;
        //cout<<top<<" ";
        //cout<<i<<endl;
        for(j=index;j<=k;j++)
        {
            pq.push(make_pair(-(top+a[j]),j));
        }
    }
    cout<<top<<"\n";
    return 0;
}
