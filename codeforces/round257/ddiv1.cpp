#include<bits/stdc++.h>
using namespace std;
const int nmax=2*1e6+9;
const int mod=1e9+7;
int a[nmax];
int s[nmax];
int n;
int p[nmax];
int bit(int x){
   int br=0;
   while(x){
      br++;
      x&=x-1;
   }
   return br;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   //s[x]-> broq na 4islata, k. kato &x i dava x
   p[0]=1;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      s[a[i]]++;
      p[i]=(2*p[i-1])%mod;
   }
   for(int i=0;i<=20;i++){
      for(int j=1;j<(1<<20);j++){
         if(j&(1<<i))s[j-(1<<i)]+=s[j];
      }
   }
   int ans=p[n]-1;
   for(int i=1;i<(1<<20);i++){
      if(bit(i)&1)ans-=p[s[i]]-1;
      else{
         ans+=p[s[i]]-1;
      }
      if(ans>=mod)ans-=mod;
      if(ans<0)ans+=mod;
   }
   cout<<ans<<"\n";
}
