#include<bits/stdc++.h>
using namespace std;
int m[10][1000];
int k;
int main()
{
    cin>>k;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=k;j++)
        {
            m[i][j]=m[i][j-1]*10+i;m[i][j]%=k;
        }
    }
    for(int j=1;j<=k;j++)
    {
        for(int i=1;i<=9;i++)
        {
            if(m[i][j]==0){cout<<i<<" "<<j<<endl;return 0;}
        }
    }
    cout<<"Impossible"<<endl;
}
