#include<bits/stdc++.h>
using namespace std;
char s[109][109];
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin>>s[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i][j]=='#')
            {

                if(i+2>n||j+1>n||j-1<1)
                {
                    cout<<"NO\n";
                    return 0;
                }
                if (s[i+1][j]!='#'||s[i+2][j]!='#'||s[i+1][j-1]!='#'||s[i+1][j+1]!='#')
                {
                    cout<<"NO\n";
                    return 0;
                }
                s[i][j]='.';
                s[i+1][j]='.';
                s[i+2][j]='.';
                s[i+1][j-1]='.';
                s[i+1][j+1]='.';
            }
        }
    }
    cout<<"YES\n";
}
