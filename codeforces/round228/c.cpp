#include<bits/stdc++.h>
using namespace std;
int n,a[109],used[109];
int br;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(br==0)
        {
            br++;
            used[br]=1;
        }
        else
        {
            if(used[1]<=a[i])used[1]++;
            else used[++br]=1;
        }
        sort(used+1,used+br+1);
    }
    cout<<br<<endl;
}
