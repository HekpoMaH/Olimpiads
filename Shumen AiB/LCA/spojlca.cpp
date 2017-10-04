#include<bits/stdc++.h>
using namespace std;
int t,x,sum;
int main()
{
    cin>>t;
    while(t--)cin>>x,sum+=max(0,x);
    cout<<sum<<"\n";
}
