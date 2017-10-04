#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+9;
map<int,int> m1,m2;
int a[nmax];
int f1[nmax];
int f2[nmax];
int bit[nmax*2];
void upd(int pos,int x){
   while(pos<=nmax){
      bit[pos]+=x;
      pos+=pos&-pos;
   }
}
int get(int pos){
   int re=0;
   while(pos!=0){
      re+=bit[pos];
      pos-=pos&-pos;
   }
   return re;
}
int n;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      m1[a[i]]++;
      f1[i]=m1[a[i]];
   }
   for(int i=n;i>=1;i--){
      m2[a[i]]++;
      f2[i]=m2[a[i]];
      upd(f2[i],1);
   }
   long long ans=0;
   for(int i=1;i<=n;i++){
      upd(f2[i],-1);  
      ans+=get(f1[i]-1);
   }
   cout<<ans<<"\n";
}
