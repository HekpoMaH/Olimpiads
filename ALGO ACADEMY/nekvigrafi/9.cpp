#include<bits/stdc++.h>
using namespace std;
#define pb push_back
map<vector<int>,int> used;
int n,k;
int main(){
   cin>>n;
   queue<vector<int> >q;
   vector<int> init;
   for(int i=1;i<=n;i++){
      int x;
      cin>>x;
      init.pb(x);
   }
   cin>>k;
   used[init]=1;
   q.push(init);
   while(!q.empty()){
      init=q.front();
      q.pop();
      for(int i=0;i<n-k+1;i++){
         vector<int> cur;
         cur=init;
         reverse(&cur[i],&cur[i+k]);
         if(used[cur]==0){
            q.push(cur);
            used[cur]=used[init]+1;
         }
      }
   }
   init.clear();
   for(int i=1;i<=n;i++){
      init.pb(i);
   }
   cout<<used[init]-1<<"\n";
}
