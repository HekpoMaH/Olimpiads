#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
int n,m;
const int pmax=19;
const int nmax=1e5+9;
const long long mod=1e9+7;
lli pw[pmax],val[pmax];
string a;
string s[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>a;
   cin>>m;
   for(int i=0;i<10;i++){
      val[i]=i;
      pw[i]=10;
   }
   for(int i=0;i<m;i++)
      cin>>s[i];
   for(int j=m-1;j>=0;j--){
      int sz=s[j].size();
      int nm=s[j][0]-'0';
      lli nmpw=1;
      lli san=0;
      for(int i=sz-1;i>2;i--){
         san=(san+(nmpw*val[s[j][i]-'0']))%mod;
         nmpw=(nmpw*pw[s[j][i]-'0'])%mod;
      }
      val[nm]=san;
      pw[nm]=nmpw;
   }
   int sz=a.size();
   lli ans=0;
   lli nmpw=1;
   for(int i=sz-1;i>=0;i--){
      ans=(ans+val[a[i]-'0']*nmpw)%mod;
      nmpw=nmpw*pw[a[i]-'0']%mod;
   }
   cout<<ans<<"\n";
}
