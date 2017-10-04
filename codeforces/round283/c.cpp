#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
const int nmax=1009;
#define pb push_back
string s[nmax];
int cn[nmax];
int n,m;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>s[i];
   }
   //0-> = |-| 1-> <
   int br=0;
   for(int col=0;col<m;col++){
      int fl=0;
      for(int i=1;i<n;i++){
         if(cn[i]==0&&s[i][col]>s[i+1][col]){
            fl=1;
            br++;
            break;
         }
      }
      if(fl==0){
         for(int i=1;i<n;i++){
            if(cn[i]==0&&s[i][col]<s[i+1][col]){
               cn[i]=1;
            }
         }
      }
   }
   cout<<br<<"\n";
}
