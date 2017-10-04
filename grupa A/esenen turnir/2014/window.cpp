#include<bits/stdc++.h>
using namespace std;
const int nmax=2009; 
int a[nmax][nmax];
int hsum[nmax][nmax];
int vsum[nmax][nmax];
int ans=0,sx,sy;
int n;
void read(){
   cin>>n;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cin>>a[i][j];
      }
   }
   for(int i=2;i<=n;i++){
      for(int j=1;j<=n;j++){
         hsum[i][j]+=hsum[i][j-1];
         if(a[i][j]==a[i-1][j])hsum[i][j]++;
         assert(hsum[i][j]>=0);
      }
   }
   for(int j=2;j<=n;j++){
      for(int i=1;i<=n;i++){
         vsum[i][j]+=vsum[i-1][j];
         if(a[i][j]==a[i][j-1])vsum[i][j]++;
         assert(vsum[i][j]>=0);
      }
   }
   //for(int i=1;i<=n;i++){
   //   for(int j=1;j<=n;j++){
   //      cout<<hsum[i][j]<<" ";
   //   }
   //   cout<<"\n";
   //}
   //cout<<"\n";
   //for(int i=1;i<=n;i++){
   //   for(int j=1;j<=n;j++){
   //      cout<<vsum[i][j]<<" ";
   //   }
   //   cout<<"\n";
   //}
}
void solve(){
   for(int i=2;i<n;i++){
      for(int j=2;j<n;j++){
         for(int sz=ans+2;sz<=n;sz+=2){
            if(i+sz-1>=n)break;
            if(j+sz-1>=n)break;
            int ii=i+sz-1,jj=j+sz-1;
            //cout<<i<<" "<<j<<" "<<sz<<"\n";
            //cout<<"cheking line "<<i<<" from "<<j<<" to "<<jj<<"\n";
            //cout<<"cheking line "<<ii+1<<" from "<<j<<" to "<<jj<<"\n";
            //cout<<"cheking col "<<j<<" from "<<i<<" to "<<ii<<"\n";
            //cout<<"cheking col "<<jj+1<<" from "<<i<<" to "<<ii<<"\n";
            //cout<<"->"<<hsum[i][jj]<<"-"<<hsum[i][j-1]<<"="<<hsum[i][jj]-hsum[i][j-1]<<"  ";
            //cout<<"->"<<hsum[ii+1][jj]<<"-"<<hsum[ii+1][j-1]<<"="<<hsum[ii+1][jj]-hsum[ii+1][j-1]<<"\n";
            //cout<<"->"<<vsum[ii][j]<<"-"<<vsum[i-1][j]<<"="<<vsum[ii][j]-vsum[i-1][j]<<"  ";
            //cout<<"->"<<vsum[ii][jj+1]<<"-"<<vsum[i-1][jj+1]<<"="<<vsum[ii][jj+1]-vsum[i-1][jj+1]<<"\n";
            if(hsum[i][jj]-hsum[i][j-1]==0&&hsum[ii+1][jj]-hsum[ii+1][j-1]==0)
               if(vsum[ii][j]-vsum[i-1][j]==0&&vsum[ii][jj+1]-vsum[i-1][jj+1]==0){
                  ans=sz;
                  //cout<<"ans="<<ans<<"\n";
                  sx=i;
                  sy=j;
               }
            if(!(hsum[i][jj]-hsum[i][j-1]==0&&vsum[ii][j]-vsum[i-1][j]==0))break;
         }
      }
   }
   cout<<ans<<" "<<sx<<" "<<sy<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
}
