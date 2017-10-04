#include<bits/stdc++.h>
using namespace std;
const int nmax=1e4+9;
const long long inf=1e18;
typedef long long lli;
lli n,k;
lli strong[nmax],weak[nmax];
string s_strong[nmax],s_weak[nmax];
string toStr(lli x){
   string re="";
   while(x!=0){
      re+=x%10+'0';
      x/=10;
   }
   reverse(re.begin(),re.end());
   return re;
}
void solve(){
   lli t;
   for(lli i=1;i<=k;i++){
      s_strong[i]+=toStr(i);
      strong[i]=s_strong[i].size();
      weak[i]=strong[i];
      s_weak[i]=s_strong[i];
   }
   for(lli i=k+1;i<=n;i++){
      strong[i]=inf;
      weak[i]=inf;
      for(lli j=1;j<=i/2;j++){
         if(weak[i]>weak[i-j]+1+weak[j]){
            weak[i]=weak[i-j]+1+weak[j];
            s_weak[i]=s_weak[i-j]+'+'+s_weak[j];
         }
      }
      for(lli j=1;j<=i;j++){
         if(j*j>i)break;
         else{
            t=i/j;
            if(j>1&&i==t*j){
               if(strong[i]>strong[t]+1+strong[j]){
                  strong[i]=strong[t]+1+strong[j];
                  s_strong[i]=s_strong[t]+'*'+s_strong[j];
               }
            }
         }
      }
      if(strong[i]<weak[i]){
         weak[i]=strong[i];
         s_weak[i]=s_strong[i];
      }
      else{
         if(weak[i]+2<strong[i]){
            strong[i]=weak[i]+2;
            s_strong[i]='('+s_weak[i]+')';
         }
      }
      //cout<<s_weak[i]<<" ada "<<s_strong[i]<<" "<<i<<"\n";
   }
}
int main(){
   cin>>n>>k;
   solve();
   //cout<<s_weak[n].size()<<"\n";
   cout<<s_weak[n]<<"\n";
}
