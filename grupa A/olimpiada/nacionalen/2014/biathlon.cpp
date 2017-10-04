#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+9;
int t[nmax];
int tr[4*nmax];
int leaf[nmax];
int n;
int ans[nmax];
void maketree(int idx,int l,int r){
   if(l==r){
      tr[idx]=1;
      leaf[l]=idx;
      return;
   }
   maketree(idx*2,l,(l+r)/2);
   maketree(idx*2+1,(l+r)/2+1,r);
   tr[idx]=tr[idx*2]+tr[idx*2+1];
}
int findidx(int idx,int l,int r,int num,int sum){
   //cout<<"idx="<<idx<<" tr["<<idx<<"]+sum="<<tr[idx]+sum<<" l="<<l<<" r="<<r<<" num="<<num<<"\n";
   if(l==r)return l;
   if(sum+tr[idx*2]>=num)return findidx(idx*2,l,(l+r)/2,num,sum);
   return findidx(idx*2+1,(l+r)/2+1,r,num,tr[idx*2]+sum);
}
void rem(int pos){
   int idx=leaf[pos];
   while(idx!=0){
      tr[idx]--;
      //cout<<"tr["<<idx<<"]-- tr="<<tr[idx]<<"\n";
      idx/=2;
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>t[i];
   }
   maketree(1,1,n);
   //cout<<tr[1]<<"\n";
   for(int i=1;i<=n;i++){
      int whataidx=findidx(1,1,n,t[i]+1,0);
      //cout<<whataidx<<" <-> "<<tr[whataidx]<<" <-> "<<i<<"\n";
      ans[whataidx]=i;
      rem(whataidx);
      //if(i==4)break;
   }
   for(int i=1;i<=n;i++){
      cout<<ans[i]<<"\n";
   }
}
