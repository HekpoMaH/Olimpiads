#include<bits/stdc++.h>
using namespace std;
int n;
int x[22],y[22];
int ans=1e9;
vector<int> idx;
int used[22];
void calcans(){
   //cout<<"calcing...\n";
   //for(int i=0;i<idx.size();i++){
   //   cout<<idx[i]<<" ";
   //}
   //cout<<"\n";
   int sum=0;
   for(int i=1;i<idx.size();i++){
      sum+=max(abs(x[idx[i]]-x[idx[i-1]]),abs(y[idx[i]]-y[idx[i-1]]));
   }
   //cout<<sum<<"\n";
   ans=min(ans,sum);
}
void go(int vz){
   if(vz==n){
      calcans();
      return;
   }
   for(int i=1;i<=2*n;i++){
      if(used[i]==0){
         used[i]=1;
         idx.push_back(i);
         go(vz+1);
         used[i]=0;
         idx.pop_back();
      }
   }
}
int main(){
   cin>>n;
   for(int i=1;i<=2*n;i++){
      cin>>x[i]>>y[i];
   }
   idx.push_back(0);
   go(0);
   cout<<ans<<"\n";
}
