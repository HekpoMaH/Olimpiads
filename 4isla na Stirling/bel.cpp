#include<bits/stdc++.h>
using namespace std;
int s[1000][1000];
int b[1000];
int main()
{
    int n,k;
    cin>>n;
    for(int i=1;i<=n;i++)s[i][i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            s[i][j]=s[i-1][j-1]+j*s[i-1][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        b[i]=b[i-1]+s[n][i];
    }
    b[0]=1;
    cout<<b[n]<<endl;
}

