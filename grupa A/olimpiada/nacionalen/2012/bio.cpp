#include<bits/stdc++.h>
using namespace std;
const int nmax=30009;
int ll[nmax],rr[nmax],uu[nmax],dd[nmax];
int nzrn,nzr[nmax];
int nzcn,nzc[nmax];
int k,n,m;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>k>>n>>m;
   for(int i=1;i<=n;i++)rr[i]=m+1;
   for(int i=1;i<=m;i++)dd[i]=n+1;
   int tr,tc;
   char td;
   for(int i=1;i<=k;i++){
      cin>>tr>>tc>>td;
      if(td=='u'&&uu[tc]<tr)uu[tc]=tr;
      if(td=='d'&&dd[tc]>tr)dd[tc]=tr;
      if(td=='l'&&ll[tr]<tc)ll[tr]=tc;
      if(td=='r'&&rr[tr]>tc)rr[tr]=tc;
   }
   //for(int i=1;i<=n+2;i++){
   //   cout<<ll[i]<<" "<<rr[i]<<"\n";
   //}
   //for(int i=1;i<=m+2;i++){
   //   cout<<uu[i]<<" "<<dd[i]<<"\n";
   //}
   for(int i=1;i<=n;i++){
      if(ll[i]>=rr[i])ll[i]=rr[i]-1;
   }
   for(int i=1;i<=m;i++){
      if(uu[i]>=dd[i])uu[i]=dd[i]-1;
   }
   int t,dirty=0;
   for(int i=1;i<=n;i++){
      if((t=m+1+ll[i]-rr[i])>0){
         dirty+=t;
         nzr[++nzrn]=i;
      }
   }
   for(int i=1;i<=m;i++){
      if((t=n+1+uu[i]-dd[i])>0){
         dirty+=t;
         nzc[++nzcn]=i;
      }
   }
   for(int i=1;i<=nzrn;i++){
      for(int j=1;j<=nzcn;j++){
         dirty-=(int)((ll[nzr[i]]>=nzc[j]||rr[nzr[i]]<=nzc[j])&&(uu[nzc[j]]>=nzr[i]||dd[nzc[j]]<=nzr[i]));
      }
   }
   cout<<dirty<<"\n";
}
