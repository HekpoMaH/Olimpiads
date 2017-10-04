#include<bits/stdc++.h>
using namespace std;
string a,s;
int n;
typedef pair<char,char> pii;
typedef long long lli;
#define fi first
#define se second
#define mp make_pair
const int nmax=200;
pii syllables[nmax];
int vow[nmax];
int cons[nmax];
int vn,cn,syllCnt;
void read(){
   cin>>a>>s>>n;
   for(int i=0;i<(int)a.size();i++){
      if(s.find(a[i])!=string::npos){
         vow[++vn]=a[i];
      }
      else cons[++cn]=a[i];
   }
   for(int i=1;i<=cn;i++){
      for(int j=1;j<=vn;j++){
         syllables[syllCnt++]=mp(cons[i],vow[j]);
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   lli t=0,num=0,st=1;
   int ans[nmax];
   while(num<n){
      t++;
      st*=syllCnt;
      num+=st;
   }
   num-=st;
   num=n-1-num;
   for(int i=t;i>=1;i--){
      ans[i]=num%syllCnt;
      num/=syllCnt;
   }
   for(int i=1;i<=t;i++){
      cout<<syllables[ans[i]].fi<<syllables[ans[i]].se;
   }
   cout<<"\n";
}
