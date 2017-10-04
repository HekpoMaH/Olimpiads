#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5;
int n,m;
queue<pair<int,int> > q;
int main(){
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      int a;
      cin>>a;
      q.push(make_pair(a,i));
   }
   int used[nmax],last;
   memset(used,0,sizeof(used));
   while(!q.empty()){
      pair<int,int> cur=q.front();
      q.pop();
      used[cur.second]+=m;
      //cout<<cur.first<<" "<<cur.second<<" "<<used[cur.second]<<"\n";
      if(used[cur.second]<cur.first)q.push(cur);
      last=cur.second;
   }
   cout<<last<<"\n";
}
