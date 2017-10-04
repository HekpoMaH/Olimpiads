#include<bits/stdc++.h>
using namespace std;
const int nmax=22;
int n,m;
int g[nmax][nmax];
int ans=0;
string a[nmax];
bool lepnat(string f,string s){
   if(f[f.size()-1]==s[0])return true;
   return false;
}
bool hasbit(int mask,int pos){
   return (mask&(1<<(pos-1)))!=0;
}
void chek(int mask){
   int st[nmax];
   memset(st,0,sizeof(st));
   for(int i=1;i<=n;i++){
      if(!hasbit(mask,i))continue;
      for(int j=1;j<=n;j++){
         if(!hasbit(mask,j))continue;
         if(g[i][j]!=0)st[i]++,st[j]--;
      }
   }
   for(int i=1;i<=n;i++)if(st[i]!=0)return;
   int curr=0;
   while(mask){
      if(mask&1)curr++;
      mask>>=1;
   }
   ans=max(ans,curr);
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         if(lepnat(a[i],a[j])){
            g[i][j]=1;
         }
      }
   }
   //for(int i=1;i<=n;i++){
   //   for(int j=1;j<=n;j++){
   //      cout<<g[i][j]<<" ";
   //   }
   //   cout<<endl;
   //}
   for(int i=0;i<(1<<n);i++){
      chek(i);
   }
   cout<<ans<<endl;
}

