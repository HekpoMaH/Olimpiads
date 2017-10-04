#include<bits/stdc++.h>
using namespace std;
const int nmax=1e4+9;
int n;
string c;
int e[nmax];
stack<int> s;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>c;
   n=c.size();
   int ans=0;
   for(int i=1;i<=n;i++){
      e[i]=e[i-1];
      if(c[i-1]=='_')continue;
      if(c[i-1]=='\\')s.push(i);
      else{
         if(s.empty()){
            continue;
         }
         ans+=i-s.top();
         e[i]=e[s.top()-1]+1;
         s.pop();
      }
   }
   cout<<e[n]<<" "<<ans<<"\n";
}
