#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
int parent[nmax],rank[nmax];
int find(int a){
   int a1=a;
   while(a!=parent[a])a=parent[a];
   parent[a1]=a;
   return a;
}
void uni(int a,int b){
   int ar=find(a);
   int br=find(b);
   if(rank[ar]<rank[br]){
      parent[ar]=br;
      return;
   }
   if(rank[br]<rank[ar]){
      parent[br]=ar;
      return;
   }
   parent[br]=ar;
   rank[ar]++;
}
int main(){
   int n;
   cin>>n;
   for(int i=1;i<=n;i++){
      rank[i]=0;
      parent[i]=i;
   }
   int m;
   cin>>m;
   for(int i=1;i<=m;i++){
      int t;
      int a,b;
      cin>>t>>a>>b;
      if(t==1){
         uni(a,b);
      }
      else{
         cout<<find(a)<<" "<<find(b)<<"\n";
      }
   }
}
