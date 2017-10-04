#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
string str;
lli dp[39][39][2];
lli numb[39];
int sza,szb;
char oper[32];
void read(){
   cin>>str;
}
lli dyn(int l,int r,int p){
   if(dp[l][r][p]!=-1){
      return dp[l][r][p];
   }
   if(l==r)return dp[l][r][p]=numb[l];
   for(int i=l;i<r;i++){
      for(int l1=0;l1<2;l1++){
         for(int l2=0;l2<2;l2++){
            lli left=dyn(l,i,l1);
            lli right=dyn(i+1,r,l2);
            lli all;
            if(oper[i]=='+')all=left+right;
            else if(oper[i]=='-')all=left-right;
            else all=left*right;
            if(dp[l][r][p]==-1)dp[l][r][p]=all;
            else if(!p){
               dp[l][r][p]=min(dp[l][r][p],all);
            }
            else{
               dp[l][r][p]=max(dp[l][r][p],all);
            }
         }
      }
   }
   return dp[l][r][p];
}
void solve(){
   for(int i=0;i<str.size();i++){
      if(i&1)oper[szb++]=str[i];
      else numb[sza++]=str[i]-'0';
   }
   for(int i=0;i<32;i++){
      for(int j=0;j<32;j++){
         dp[i][j][0]=dp[i][j][1]=-1;
      }
   }
   cout<<dyn(0,sza-1,0)<<"\n";
}
int main(){
   read();
   solve();
}
