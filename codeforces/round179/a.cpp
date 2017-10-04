#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
using namespace std;
int n;
int a[109];
int used[10099],mn,br,l=0;
vector<int> v;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        used[a[i]]++;
    }
    for(int i=1;i<=1009;i++)
    {
        mn=max(mn,used[i]);
    }
    if(mn>(n+1)/2)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
