#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const int maxn=200,mod=1e6+7;
int n,m,k;
string c[maxn];
lli tab[maxn][maxn],s,e,ans;
const int dx[6]={0,1,-1,0,0};
const int dy[6]={0,0,0,1,-1};
void read(){
   cin>>n>>m>>k;
   for(int i=0;i<n;i++){
      cin>>c[i];
   }
}
inline int code(int x,int y){
   return x*m+y+1;
}
inline bool iner(int x,int y){
   return (x>=0&&x<n&&y>=0&&y<m);
}
void init(){
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(c[i][j]=='X')continue;
         if(c[i][j]=='F'){
            e=code(i,j);
            continue;
         }
         if(c[i][j]=='D')s=code(i,j);
         for(int kk=1;kk<=4;kk++){
            int i1=i+dx[kk];
            int j1=j+dy[kk];
            if(iner(i1,j1)&&c[i1][j1]!='D'&&c[i1][j1]!='X'){
               tab[code(i,j)][code(i1,j1)]=1;
            }
         }
      }
   }
}
lli tmp[maxn][maxn];
int n1;
void mult(lli a[maxn][maxn],lli b[maxn][maxn],bool p3){
   lli t[maxn][maxn];
   memset(t,0,sizeof(t));
   for(int i=1;i<=n1;i++){
      for(int j=1;j<=n1;j++){
         for(int kk=1;kk<=n1;kk++){
            t[i][j]=(t[i][j]+a[i][kk]*b[kk][j]%mod)%mod;
         }
      }
   }
   if(p3==0)memcpy(tmp,t,sizeof(t));
   else memcpy(tab,t,sizeof(t));
}
void solve(){
   n1=n*m;
   if(k)ans+=tab[s][e];
   for(int i=3;i<=k;i*=3){
      mult(tab,tab,0);
      mult(tmp,tab,1);
      ans=(ans+tab[s][e])%mod;
   }
   cout<<ans<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   init();
   solve();
}
