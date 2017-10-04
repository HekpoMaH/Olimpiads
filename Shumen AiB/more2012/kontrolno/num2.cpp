//moje i da stane
#include<iostream>
#include<string>
using namespace std;
int dp[102][102],j,br;
int used[102],n;
string num;
int main()
{
    cin>>num;
    n=num.size();
    for(int i=0;i<n;i++)dp[i][i]=1;
    for(int i=0;i<n;i++)
    {
        if(i==0)j=i+1;
        else j=i;
        while(j<n)
        {
            br=1;
            for(int k=i;k<j;k++)if(num[k]!=num[j])br++;
            dp[i][j]=max(dp[i][j],br*dp[i][j-1]);
            cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<dp[i][j-1]<<" "<<br<<endl;
            j++;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum+=dp[i][j];
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<sum<<endl;
    return 0;
}