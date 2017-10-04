#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+9;
int n;
int p[nmax];
int l[nmax];
int l1;
void lbuild(){
   stack<int> st;
   st.push(INT_MIN);
   for(int i=1;i<=n;i++){
      l[i]=0;
      while(st.top()>p[i])
         st.pop(),l[i]++;
      st.push(p[i]);
   }
}
bool cmp(){
   stack<int> st;
   int pe;
   bool ideq;
   st.push(INT_MIN);
   indeq=true;
   for(int i=1;i<=n;i++){
      cin>>pe;
      l1=0;
      while(st.top()>pe&&ideq){
         st.pop();l1++;
      }
      st.push(pe);
      if(l1!l[i])ideq=false;
   }
   return indeq;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>p[i];
   }
   lbuild();
   if(cmp()){
      cout<<"YES\n";
   }
   else cout<<"NO\n";
}
