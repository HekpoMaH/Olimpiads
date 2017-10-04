#include<iostream>
using namespace std;
struct sm
{
    double cena;
    double vis;double sh;
};
sm mat[1000][1000];
double v[1000],s[1000];
int n,ks;
double mn;
void sbor(double &x,double &y,int i,int j)
{
    for(int f=i;f<=j;f++){x+=s[f];y+=v[f];}
}
double dp[1000][1000];
int main()
{
    cin>>n>>ks;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>v[i];
        mat[i][i].cena=0;
        mat[i][i].vis=v[i];
        mat[i][i].sh=s[i];
    } 
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n-k;i++)
        {
            sbor(mat[i][i+k].sh,mat[i][i+k].vis,i,i+k);
            mat[i][i+k].cena=mat[i][i].sh*mat[i+1][i+k].vis+mat[i][i].cena+mat[i+1][i+k].cena;
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=9999999;
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int red=2;red<=n;red++)
    {
        for(int ds=1;ds<red&&ds<=ks;ds++)
        {
            if(ds==1)dp[red][ds]=mat[1][red].cena;
            else
            {
                for(int i=ds-1;i<red;i++)
                {
                    if(dp[i][ds-1]+mat[i+1][red].cena<dp[red][ds])dp[red][ds]=dp[i][ds-1]+mat[i+1][red].cena;
                    //cout<<"dp["<<i<<"]["<<ds-1<<"]="<<dp[i][ds-1]<<" "<<"mat["<<i+1<<"]["<<red<<"]="<<mat[i+1][red].cena<<" "<<"dp["<<red<<"]["<<ds<<"]="<<dp[red][ds]<<endl;
                }
            }
            //cout<<"red="<<red<<" "<<"da stane="<<ds<<" "<<dp[red][ds]<<endl<<"----------------"<<endl;
        }
    }
    cout<<dp[n][ks]<<endl;
    //cout<<mat[1][3].cena<<endl;
    return 0;
}
/*
7 3
2 0.3
4 1.1
1 0.5
3 0.9
3 0.9
4 0.9
2 1
*/