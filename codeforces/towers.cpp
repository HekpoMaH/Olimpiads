#include<iostream>
#include<algorithm>
using namespace std;
int n,a,b[1005];
int mx,br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        b[a]++;
    }
    for(int i=1;i<=1000;i++)
    {
        if(b[i]!=0)br++;
        mx=max(mx,b[i]);
    }
    cout<<mx<<" "<<br<<endl;
    return 0;
}
