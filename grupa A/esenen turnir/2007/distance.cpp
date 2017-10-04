#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
typedef pair<unsigned int,unsigned int> pii;
const int nmax=(1<<21)+2;
unsigned int dp[nmax];
unsigned int n;
pii stud[29];
unsigned dist(int i,int j){
   return (stud[i].fi-stud[j].fi)*(stud[i].fi-stud[j].fi)+(stud[i].se-stud[j].se)*(stud[i].se-stud[j].se);
}
unsigned int solve(unsigned mask,unsigned brstud,unsigned lbit){
   if(brstud>=n){
      //assert(mask==0);
      return dp[mask]=0;
   }
   if(dp[mask]!=(unsigned)(-1))return dp[mask];
   unsigned int best=0;
   for(unsigned int i=0;i<n-1;i++){
      if(mask&(1<<i)){
         unsigned mask2;
         for(unsigned int j=i+1;j<n-1;j++){
            if(mask&(1<<j)){
               //cout<<i<<" "<<j<<"\n";
               mask2=mask;mask2^=(1<<i);mask2^=(1<<j);
               //for(unsigned I=0;I<n;I++){
               //   cout<<(bool)(mask2&(1<<I));
               //}
               //cout<<"\n";
               //for(unsigned I=0;I<n;I++){
               //   cout<<(bool)(mask&(1<<I));
               //}
               //cout<<"\n";
               //cout<<"---------\n";
               best=max(best,solve(mask2,brstud+2,lbit)+dist(i,j));
            }
         }
         if(lbit==1){
            mask2=mask;
            mask2^=(1<<i);
            best=max(best,solve(mask2,brstud+2,0)+dist(i,n-1));
         }
      }
   }
   return dp[mask]=best;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   assert((1<<(n-1))<nmax);
   for(int i=0;i<n;i++){
      cin>>stud[i].first>>stud[i].second;
   }
   //cout<<(unsigned)(-1)<<"\n";
   for(int i=0;i<nmax;i++){
      dp[i]=(unsigned)(-1);//1432943294
   }
   dp[0]=0;
   unsigned wh=1;
   for(unsigned int i=1;i<n-1;i++){
      wh*=2;
      wh+=1;
   }
   //cout<<wh<<" "<<nmax<<"\n";
   //for(unsigned int i=0;i<n;i++){
   //   assert(wh&(1<<i));
   //}
   cout<<solve(wh,0,1)<<".000\n";
   
}
