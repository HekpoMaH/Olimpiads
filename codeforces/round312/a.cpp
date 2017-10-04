#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
const int nmax=1e5+9;
const int offset=1e5+9;
#define mp make_pair
#define pb push_back
lli n;
lli x[nmax+offset];
lli x2[nmax+offset];
lli a,b;
lli mn=nmax*2;
lli mx=-mn;
lli ans;
void solve(lli dir){
   lli cur=0;
   lli pos=offset;
   while(0<=pos&&pos<=nmax+offset-2){
      //cout<<pos<<"\n";
      //cout.flush();
      if(x[pos]!=0){
         cur+=(lli)x[pos];
         x[pos]=0;
         dir=-dir;
      }
      pos+=dir;
      int sp;
      //cin>>sp;
   }
   ans=max(ans,cur);
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a>>b;
      x[a+offset]=b;
      x2[a+offset]=x[a+offset];
   }
   solve(1);
   for(int i=0;i<=offset+offset-1;i++){
      x[i]=x2[i];
   }
   solve(-1);
   cout<<ans<<"\n";
}
