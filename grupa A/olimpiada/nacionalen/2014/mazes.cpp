#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef vector<lli> vl;
typedef vector<vl> ma3x;
const lli mod=1234567;
int m;
lli n;
ma3x a;
void init(){
   m-=2;
   a.resize(1<<m);
   for(int i=0;i<(1<<m);i++){
      a[i].resize(1<<m,0);
   }
   for(int mask1=0;mask1<(1<<m);mask1++){
      for(int nxt=0;nxt<(1<<m);nxt++){
         int mask2=nxt;
         for(int i=0;i<m;i++){
            if(!((mask2>>i)&1)){
               bool fl=false;
               for(int j=i;j<m;j++){
                  if((mask2>>j)&1)break;
                  if(!((mask1>>j)&1)){
                     fl=true;
                     break;
                  }
               }
               if(fl)continue;
               for(int j=i-1;j>=0;j--){
                  if((mask2>>j)&1)break;
                  if(!((mask1>>j)&1)){
                     fl=true;
                     break;
                  }
               }
               if(fl)continue;
               mask2|=(1<<i);
            }
         }
         a[mask1][mask2]++;
      }
   }
}
ma3x mult(ma3x A, ma3x B){
   ma3x C;
   C.resize(1<<m);
   for(int i=0;i<(1<<m);i++){
      C[i].resize(1<<m,0);
   }
   for(int i=0;i<(1<<m);i++){
      for(int j=0;j<(1<<m);j++){
         for(int k=0;k<(1<<m);k++){
            C[i][j]+=A[i][k]*B[k][j];
            if(C[i][j]>=mod)C[i][j]%=mod;
         }
      }
   }
   return C;
}
ma3x go(ma3x base,lli pw){
   if(pw==1)return base;
   if(pw&1)return mult(base,go(base,pw-1));
   return go(mult(base,base),pw>>1);
}
void solve(){
   ma3x res;
   res=go(a,n);
   lli ret=0;
   for(int i=0;i<(1<<m)-1;i++){
      ret+=res[0][i];
      ret%=mod;
   }
   cout<<ret<<"\n";
}
int main(){
   cin>>m>>n;
   init();
   solve();
}

