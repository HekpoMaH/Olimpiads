#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100][100],br,ans2;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==1)
            {
                br++;
                if(i==1||i==n)ans2=1;
                if(j==1||j==m)ans2=1;
            }
        }
    }
    if(ans2==1)cout<<2<<endl;
    else if(br==1){cout<<4<<endl;return 0;}
    else cout<<4<<endl;
    return 0;
}

