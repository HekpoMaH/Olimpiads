#include<bits/stdc++.h>
using namespace std;
const int nmax=22;
int n,m;
int g[nmax][nmax];
string a[nmax];
bool lepnat(string f,string s){
   if(f[f.size()-1]==s[0])return true;
   return false;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
         if(lepnat(a[i],a[j])){
            g[i][j]=g[j][i]=1;
      }
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cout<<g[i][j]<<" ";
      }
      cout<<endl;
   }
}
