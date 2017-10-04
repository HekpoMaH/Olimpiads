#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,pos1=1,pos2;
    cin>>n;pos2=n*n;
    for(int i=0;i<n;i++)
    {
        for(int j=i*(n/2)+1;j<=i*(n/2)+n/2;j++)cout<<j<<" ";
        for(int j=n*n-i*(n/2)-n/2+1;j<=n*n-i*(n/2);j++)cout<<j<<" ";
        cout<<endl;
    }
}
