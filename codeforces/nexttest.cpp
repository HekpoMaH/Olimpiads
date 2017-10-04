#include<iostream>
#include<algorithm>
using namespace std;
int n,used[3003],a;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;used[a]=1;
    }
    for(int i=1;i<=3005;i++)
    {
        if(used[i]==0){cout<<i<<endl;return 0;}
    }
    return 0;
}