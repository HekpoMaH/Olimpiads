#include<bits/stdc++.h>
using namespace std;
vector<int> dp[109][109];
//i hate oz too
vector<string> dp2[109][109];
string s1,s2,virus,ans;
int mx;
bool dnc(string sb)
{
    int fl;
    for(int i=0;i<sb.size();i++)
    {
        fl=0;
        if(i+virus.size()-1<sb.size())
        {
               for(int j=0;j<virus.size();j++)if(sb[i+j]!=virus[j]){fl=1;break;}
        }
        else fl=1;
        if(fl==0)return false;
    }
    return true;
}
string chk(vector<string> muh)
{
    int i,mxi=0,mxd=-1;//if(muh.size()!=0)cout<<"D"<<endl;
    for(i=0;i<muh.size();i++)
    {
        //if(muh[i]!="")cout<<muh[i]<<" "<<dnc(muh[i])<<endl;
        if(dnc(muh[i])==true)
        {
            //cout<<muh[i]<<endl;
            if(muh[i].size()>mxi)
            {
                mxi=muh[i].size();mxd=i;
            }
        }
    }
    if(mxd==-1)return "-1";
    return muh[mxd];
}
int main()
{
    int i,j,k;
    string mamamu="";
    cin>>s1>>s2>>virus;
    for(i=1;i<=s1.size();i++)
    {
        mamamu+=s1[i-1];
        dp[i][0].push_back(0);dp2[i][0].push_back("");
    }
    for(i=1;i<=s2.size();i++)
    {
        mamamu+=s2[i-1];
        dp[0][i].push_back(0);dp2[0][i].push_back("");
    }
    int maax;
    for(i=1;i<=s1.size();i++)
    {
        for(j=1;j<=s2.size();j++)
        {
            //cout<<i<<" "<<j<<" "<<dp[i-1][j][0]<<" "<<dp[i][j-1][0]<<endl;
            /*if(s1[i-1]!=s2[j-1])
            {*/
                //if(i==8&&j==8)cout<<dp[i-1][j][0]<<" "<<dp[i][j-1][0]<<endl;
                if(dp[i][j-1][0]>dp[i-1][j][0])
                {
                    maax=dp[i][j-1][0];
                    //if(dp[i][j-1][0]!=0)cout<<"E'<<"<<endl;
                    for(k=0;k<dp[i][j-1].size();k++)
                    {
                        dp[i][j].push_back(dp[i][j-1][k]);
                        dp2[i][j].push_back(dp2[i][j-1][k]);
                    }
                }
                else
                {
                    maax=dp[i-1][j][0];
                    for(k=0;k<dp[i-1][j].size();k++)
                    {
                        dp[i][j].push_back(dp[i-1][j][k]);
                        dp2[i][j].push_back(dp2[i-1][j][k]);
                    }
                }
            //}
            if(s1[i-1]==s2[j-1])
            {
                if(maax>dp[i-1][j-1][0]+1)continue;
                dp[i][j].clear();dp2[i][j].clear();
               // cout<<i<<" "<<j<<" "<<dp[i-1][j-1][0]<<" ";;
                for(k=0;k<dp[i-1][j-1].size();k++)
                {
                    dp[i][j].push_back(dp[i-1][j-1][k]+1);
                    dp2[i][j].push_back(dp2[i-1][j-1][k]+s1[i-1]);
                }
                //cout<<dp[i][j][0]<<endl;
            }
        }
    }
    //cout<<"S"<<endl;
    string wtf;
    for(i=1;i<=s1.size();i++)
    {
        for(j=1;j<=s2.size();j++)
        {
            wtf=chk(dp2[i][j]);
            //cout<<i<<" "<<j<<" "<<wtf<<endl;
            if(wtf=="-1")continue;
            if(mx<wtf.size())
            {
                mx=wtf.size();ans=wtf;
            }
        }
    }
    if(mx==0)cout<<0<<endl;
    else cout<<ans<<endl;
}
