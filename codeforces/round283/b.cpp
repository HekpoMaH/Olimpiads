#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
int n;
int a[nmax];
int curn[nmax];
int ans[nmax];
void upans(){
   for(int i=1;i<=n;i++){
      ans[i]=curn[i];
   }
}
void chek(int j){
   int br=0;
   for(int i=j;i<=n;i++)curn[++br]=a[i];
   for(int i=1;i<j;i++){
      curn[++br]=a[i];
   }
   for(int i=1;i<=n;i++){
      if(curn[i]>ans[i])return;
      if(curn[i]<ans[i]){
         upans();
         return;
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   string s;
   cin>>s;
   for(int i=1;i<=n;i++){
      a[i]=s[i-1]-'0';
      ans[i]=a[i];
   }
   for(int i=0;i<10;i++){
      for(int j=1;j<=n;j++){
         chek(j);
      }
      for(int j=1;j<=n;j++){
         a[j]++;
         a[j]%=10;
      }
   }
   for(int i=1;i<=n;i++)cout<<ans[i];cout<<"\n";
}
