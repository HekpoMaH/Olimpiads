#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6*4+9;
const int mod=1<<20;
int dp[nmax],sum[nmax],letter[nmax];
int last[nmax];
string s;
int wre(char ch){
   if(ch=='A')return 0;
   if(ch=='G')return 1;
   if(ch=='T')return 2;
   if(ch=='C')return 3;
   return 9;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>s;
   int br=0;
   for(int i=0;i<s.size();i+=3){
      int w1,w2,w3;
      w1=wre(s[i]);w2=wre(s[i+1]);w3=wre(s[i+2]);
      letter[++br]=w1*4*4+w2*4+w3;
   }
   dp[0]=1;
   sum[0]=1;
   //cout<<letter[1]<<" "<<letter[2]<<" "<<letter[3]<<"\n";
   for(int i=1;i<=br;i++){
      //cout<<last[letter[i]]-1<<"\n";
      if(last[letter[i]]-1>=0)dp[i]=(mod+sum[i-1]-sum[last[letter[i]]-1])%mod;
      else dp[i]=(mod+sum[i-1])%mod;
      sum[i]=(mod+sum[i-1]+dp[i])%mod;
      last[letter[i]]=i;
   }
   cout<<sum[br]-1<<"\n";
}
