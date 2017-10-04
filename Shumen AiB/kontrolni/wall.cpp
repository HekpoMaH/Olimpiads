#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
int a[nmax];
int b[nmax];
stack<int> koli4ka;
int n;
int br;
bool chek(int x){
   stack<int> st=koli4ka;
   br=0;
   int fl=1;
   for(int i=1;i<=n;i++){
      if(a[i]>=x)continue;
      int pl=0;
      while(!st.empty()){
         if(st.top()+a[i]>=x){
            pl=st.top();
            st.pop();
            br++;
            break;
         }
         st.pop();
      }
      if(pl+a[i]<x)fl=0;
   }
   return fl;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   int l=1e9,r=1e9,mid;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      l=min(l,a[i]);
   }
   int k;
   cin>>k;
   for(int i=1;i<=k;i++){
      cin>>b[i];
   }
   for(int i=k;i>=1;i--){
      koli4ka.push(b[i]);
   }
   while(l+1<r){
      mid=(l+r)/2;
      if(chek(mid)){
         l=mid;
      }
      else r=mid;
   }
   chek(l);
   cout<<l<<" "<<br<<"\n";
}
