#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+9;
const int inf=1e9;
int subs[nmax];
int n,m;
int otg(){
   stack<int> st;
   int br=0,mx=0;
   st.push(inf);
   for(int i=1;i<=n;i++){
      br=0;
      while(st.top()<subs[i]){
         st.pop();
         br++;
      }
      st.push(subs[i]);
      mx=max(mx,br);
   }
   return mx;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>subs[i];
   }
   for(int i=1;i<=m;i++){
      int x;
      cin>>x;
      if(x==0)cout<<otg()<<"\n";
      else{
         swap(subs[x],subs[x+1]);
      }
   }
}
