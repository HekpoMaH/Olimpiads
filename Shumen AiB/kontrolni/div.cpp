#include<bits/stdc++.h>
using namespace std;
const int mxl=13;
const int Sqr=1e6;
#define pb push_back
#define mp make_pair
typedef long long lli;
typedef pair<lli,lli> pii;

lli n,m;
vector<int> vn;
pii d[mxl][Sqr];
int main(){
   cin>>n>>m;
   lli sqr=sqrt(n);
   lli n2=n;
   while(n2!=0){
      vn.pb(n2%10);
      n2/=10;
   }
   if(vn.size()==1){
      if(n%m==0){
         cout<<n<<"\n";
      }
      else{
         cout<<"0\n";
      }
   }
   if(m>sqr){
      lli ans=-1;
      int best=100;
      for(int i=0;;i++){
         lli cur=m*i;
         vector<int> v;
         while(cur){
            v.pb(cur%10);
            cur/=10;
         }
         if(v.size()>vn.size())break;
         if(v.size()<vn.size())continue;
         int br=0;
         for(int j=0;j<v.size();j++){
            if(v[j]!=vn[j])br++;
         }
         if(br<best){
            best=br;
            ans=i*m;
         }
      }
      cout<<ans<<"\n";
   }
   else{
      lli pw10[20];
      pw10[0]=1;
      for(int i=1;i<mxl;i++){
         pw10[i]=pw10[i-1]*10%m;
      }
      for(int i=0;i<mxl;i++){
         for(int j=0;j<Sqr;j++){
            d[i][j]=mp(100,-1);
         }
      }
      d[0][0]=mp(0,-1);
      for(int i=1;i<=vn.size();i++){
         int start=0;
         if(i==vn.size()){
            start=1;
         }
         int pw=pw10[i-1];
         for(int j=start;j<10;j++){
            for(int k=0;k<m;k++){
               d[i][(k+j*pw)%m]=min(d[i][(k+j*pw)%m],mp(d[i-1][k].first+(vn[i-1]!=j),(lli)j));
            }
         }
      }
      if(d[vn.size()][0].first==100){
         cout<<-1<<"\n";
         return 0;
      }
      vector<int> ans;
      int rem=0;
      for(int i=vn.size();i>0;i--){
         int now=pw10[i-1];
         ans.pb(d[i][rem].second);
         rem=(rem-now*d[i][rem].second)%m;
         if(rem<0){
            rem+=m;
         }
      }
      for(int i=0;i<ans.size();i++){
         cout<<ans[i];
      }
      cout<<"\n";
   }
}
