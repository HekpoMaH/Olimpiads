#include<bits/stdc++.h>
using namespace std;
const int maxn=109;
int dp[3][3][105];
int grundy(int p,int len,int nx) {
    if(len==0)
        return dp[p][nx][len]=0;
    else if(dp[p][nx][len]!=-1)
        return dp[p][nx][len];
    set<int> s;
    for (int k=1;k<=len;k++){
        if(!((k==1&&p==1)||(k==len&&nx==1)))
            s.insert(grundy(p,k-1,1)^grundy(1,len-k,nx));
        if (!((k==1&&p==2)||(k==len&&nx==2)))
            s.insert(grundy(p,k-1,2)^grundy(2,len-k,nx));
    }
    dp[p][nx][len] = 0;
    while (s.count(dp[p][nx][len]))
        dp[p][nx][len]++;
    return dp[p][nx][len];
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   memset(dp,-1,sizeof(dp));
   int t;
   cin>>t;
   string s;
   while(t--){
      cin>>s;
      int pl=0;
      for(int i=0;i<s.size();i++)
         if(s[i]!='.')pl^=1;
      
      int sgs=0;
      for(int i=0;i<s.size();i++){
         if(s[i]!='.')continue;

         int lef,righ;
         if(i-1<0)lef=0;
         else if(s[i-1]=='X')lef=1;
         else lef=2;

         int j;
         for(j=i;j<s.size();j++){
            if(s[j]!='.')break;
         }
         //cout<<"j="<<j<<endl;
         if(j==s.size())righ=0;
         else if(s[j]=='X')righ=1;
         else righ=2;
         //cout<<lef<<" "<<j-i<<" "<<righ<<" "<<grundy(lef,j-i,righ)<<"\n";
         sgs^=grundy(lef,j-i,righ);
         i=j;
      }
      int a=grundy(0,100,0);
      for(int i=0;i<=2;i++)
         for(int j=0;j<=2;j++)
            for(int k=0;k<=100;k++)
               a=grundy(i,k,j);
      
      for(int i=0;i<=2;i++){
         for(int j=0;j<=2;j++){
            cout<<"i="<<i<<" j="<<j<<"\n";
            for(int k=0;k<=100;k++){
               cout<<dp[i][j][k]<<" ";
            }
            cout<<"\n";
         }
      }
      //cout<<sgs<<" "<<pl<<"\n";
      if((!pl&&sgs)||(pl&&!sgs))
         cout<<"Possible.\n";
      else
         cout<<"Impossible.\n";
   }
}
