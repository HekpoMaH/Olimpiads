#include<bits/stdc++.h>
using namespace std;
int g;
int n;
int ans[1009][2],re[1009][2];
//ostava6ti vzeti
void solve()
{
    ans[0][0]=1;ans[0][1]=0;
    for(int i=1;i<=1000;i++)
    {
        for(int k=1;k<=3;k++)
        {
            if(i-k>=0&&(k==1||k==3))
            {
                if(ans[i-k][1]==0)ans[i][0]=1,re[i][0]=k;
                if(ans[i-k][0]==0)ans[i][1]=1,re[i][1]=k;
            }
            else
            {
                if(i-k>=0&&ans[i-k][0]==0)ans[i][0]=1,re[i][0]=k;
                if(i-k>=0&&ans[i-k][1]==0)ans[i][1]=1,re[i][0]=k;
            }
        }
    }
    /*for(int i=0;i<=20;i++)
    {
        for(int j=0;j<=1;j++)cout<<ans[i][j]<<" ";
        cout<<endl;
    }*/
}
int main()
{
    cin>>g;
    solve();
    for(int i=1;i<=g;i++)
    {
        cin>>n;
        //cout<<"n="<<n<<" "<<ans[n-1][0]<<endl;
        if(ans[n][0]==0)
        {
            cout<<"second"<<endl;
        }
        else cout<<"first"<<" "<<re[n][0]<<endl;
    }
}
