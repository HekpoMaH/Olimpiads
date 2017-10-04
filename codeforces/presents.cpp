#include<iostream>
#include<algorithm>
using namespace std;
int a[104];
int n,s,s2,br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[j]==i)
            {
                if(i<n)cout<<j<<" ";
                else cout<<j<<endl;
            }
        }
    }
    return 0;
}