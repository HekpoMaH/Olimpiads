/*
ID: dobrikg1
PROG: wormhole
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
const int nmax=13;
int x[nmax],y[nmax];
int n;
int partner[nmax];
int nextRight[nmax];
bool checkCycle(){
   int nxt;
   for(int i=1;i<=n;i++){
      nxt=i;
      for(int j=1;j<=n;j++){
         nxt=partner[nextRight[nxt]];
      }
      if(nxt!=0)return true;
   }
   return false;
}
int chek(){
   int i,count=0;
   for(i=1;i<=n;i++){
      if(partner[i]==0)break;
   }
   if(i>n)return checkCycle();
   for(int j=i+1;j<=n;j++){
      if(partner[j]==0){
         partner[j]=i;
         partner[i]=j;
         count+=chek();
         partner[i]=partner[j]=0;
      }
   }
   return count;
}
int main(){
   freopen("wormhole.in", "r", stdin);
   freopen("wormhole.out", "w", stdout);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>x[i]>>y[i];
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         if(y[i]==y[j]&&x[j]>x[i]&&(nextRight[i]==0||x[j]<x[nextRight[i]])){
            nextRight[i]=j;
         }
      }
   }
   cout<<chek()<<"\n";
}
