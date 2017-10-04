#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli c[100][100];
string s;
int n;
int a[100];
int p[100];
void read(){
   cin>>s;
   n=s.size();
   for(int i=0;i<n;i++){
      a[s[i]-'A']++;
   }
}
void makecomb(){
   for(int i=1;i<=40;i++){
      for(int j=0;j<=i;j++){
         if(j==0||j==i){
            c[i][j]=1;
         }
         else c[i][j]=c[i-1][j-1]+c[i-1][j];
      }
   }
}
void solve(){
   lli ans=1;
   for(int i=0;i<26;i++){
      if(a[i]!=0){
         ans*=c[n][a[i]];
         n-=a[i];
      }
   }
   cout<<ans<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   read();
   makecomb();
   solve();
}
