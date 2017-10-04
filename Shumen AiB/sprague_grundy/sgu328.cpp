#include<bits/stdc++.h>
using namespace std;
const int maxn=100009;
int dp[3][3][maxn];
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
   int t=1;
   string s;
   int n;
   cin>>n;
   while(t--){
      cin>>s;
      int pl=0;
      for(int i=0;i<n;i++)
         if(s[i]!='0')pl^=1;
      
      int sgs=0;
      for(int i=0;i<n;i++){
         if(s[i]!='0')continue;

         int lef,righ;
         if(i-1<0)lef=0;
         else if(s[i-1]=='1')lef=1;
         else lef=2;

         int j;
         for(j=i;j<n;j++){
            if(s[j]!='0')break;
         }
         //cout<<"j="<<j<<endl;
         if(j==s.size())righ=0;
         else if(s[j]=='1')righ=1;
         else righ=2;
         //cout<<lef<<" "<<j-i<<" "<<righ<<" "<<grundy(lef,j-i,righ)<<"\n";
         sgs^=grundy(lef,j-i,righ);
         i=j;
      }
      //cout<<sgs<<" "<<pl<<"\n";
      if(sgs)
         cout<<"FIRST\n";
      else
         cout<<"SECOND\n";
   }
}
