#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
const int mmax=6;
int n,m,k,cnt[nmax][mmax],rmq[mmax][20][nmax],lg[nmax];
int findmax(int index,int left,int right){
   int l=lg[right-left+1];
   return max(rmq[index][l][left],rmq[index][l][right-(1<<l)+1]);
}
bool chek(int l,bool print){
   for(int i=1;i+l-1<=n;i++){
      int s=0;
      for(int j=1;j<=m;j++){
         s+=findmax(j,i,i+l-1);
      }
      if(s<=k){
         if(print){
            for(int j=1;j<=m;j++){
               cout<<findmax(j,i,i+l-1)<<" ";
            }
            cout<<"\n";
            exit(0);
         }
         return 1;
      }
   }
   return 0;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m>>k;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         cin>>cnt[i][j];
      }
   }
   for(int i=1;i<=n;i++){
      lg[i]=int(log2(i));
   }
   for(int k=1;k<=m;k++){
      for(int i=1;i<=n;i++){
         rmq[k][0][i]=cnt[i][k];
      }
      for(int i=1;(1<<i)<=n;i++){
         for(int j=1;j<=n;j++){
            rmq[k][i][j]=max(rmq[k][i-1][j],rmq[k][i-1][j+(1<<(i-1))]);
         }
      }
   }
   int left=-1,right=n,mid;
   while(left+1<right){
      mid=(left+right)/2;
      if(chek(mid,0))left=mid+1;
      else right=mid-1;
   }
   //cout<<left<<" "<<chek(left,0)<<"afd\n";
   if(left==0){
      for(int i=1;i<=m;i++){
         cout<<"0 ";
      }
      cout<<"\n";
   }
   else{
      chek(left,1);
      if(chek(left,1)==0)chek(left-1,1);
   }
}
