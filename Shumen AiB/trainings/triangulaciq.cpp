//informatics.mccme.ru - 591
#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+9;
#define pb push_back
int n,m;
int c[nmax],o[nmax],l[nmax],nxt[nmax],fi[nmax],se[nmax];
void read(){
   cin>>n>>m;
   o[1]=2;
   c[n]=2;
   for(int i=1;i<n;i++)o[i]=c[i]=1;
   for(int i=1;i<=m;i++){
      int x,y;
      cin>>x>>y;
      if(x>y)swap(x,y);
      o[x]++;c[y]++;
   }
}
void solve(){
   if(m==n-3){
      cout<<0<<"\n";
      return;
   }
   int lvl=0;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=c[i];j++){
         if(l[lvl+1]>2){
            vector<int> v;
            v.pb(i);
            v.pb(max(1,fi[lvl+1]));
            v.pb(max(1,se[lvl+1]));
            cout<<1+l[lvl+1]<<" ";
            for(int k=3;k<=l[lvl+1];k++)v.pb(max(1,nxt[k]));
            sort(v.begin(),v.end());
            for(size_t k=0;k<v.size();k++){
               cout<<v[k]<<" ";
            }
            cout<<"\n";
            exit(0);
         }
         l[lvl+1]=0;lvl--;
      }
      for(int j=1;j<=o[i];j++){
         lvl++;
         l[lvl]++;
         if(l[lvl]==1)fi[lvl]=i;
         if(l[lvl]==2)se[lvl]=i;
         if(l[lvl]>2)nxt[l[lvl]]=i;
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
}

