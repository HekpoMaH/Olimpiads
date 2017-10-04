#include<bits/stdc++.h>
using namespace std;
int n;
int dp[29][109],l,lp=1;
string s;
void decrn(int idx)
{
    int sum=0;
    for(int j=lp;j<=26;j++)
        {
            //cout<<idx<<" "<<j<<" "<<dp[j][idx]<<" "<<n<<endl;
            if(dp[j][idx]<n)n-=dp[j][idx];
            else
            {
                s+=(char)('a'+j-1);
                //cout<<n<<" "<<s<<" "<<j<<endl;
                lp=j+1;
                return;
            }
        }
}
int getl(int x)
{
    int starter=x;
    for(int i=1;i<=26;i++)
    {
        starter=x;
        for(int j=1;j<=26;j++)
        {
            if(dp[j][i]<x)x-=dp[j][i];
            else{l=i;return starter;}
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=26;i++)dp[i][1]=1;
    for(int j=2;j<=100;j++)
    {
        for(int i=1;i<=26;i++)
        {
            for(int k=i+1;k<=26;k++)
            {
                dp[i][j]+=dp[k][j-1];
            }
        }
    }
    int suma=0;
    for(int i=1;i<=26;i++)
    {
        suma+=dp[i][1];
    }
    //cout<<suma<<" "<<dp[2][2]<<endl;
    n=getl(n);
    //cout<<n<<endl;
    //int x=getl(n);
    int i=l;
    //if(l==1)n++;
    //cout<<l<<endl;
    while(i!=0)
    {
        decrn(i);
        i--;//cout<<s<<" "<<i<<" "<<lp<<endl;
    }
    cout<<s<<endl;
}
