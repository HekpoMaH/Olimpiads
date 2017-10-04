#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int nmax=2009;
int n,m,tab[nmax][nmax],dp[nmax][nmax];
int dpleft[nmax],dpright[nmax],row[nmax];
stack<pair<int,int> > st;
void input(){
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         cin>>tab[i][j];
         if(tab[i][j]==0){
            tab[i][j]=tab[i-1][j]+1;
         }
         else tab[i][j]=0;
      }
   }
}
void solve(){
   int sz,sum=0;
   for(int i=1;i<=n;i++){
      memset(dpleft,0,sizeof(dpleft));
      memset(dpright,0,sizeof(dpright));
      for(int j=1;j<=m;j++){
         sum=0;
         while(!st.empty()){
            if(st.top().first>=tab[i][j]){
               sum+=st.top().second;
               st.pop();
            }
            else break;
         }
         dpleft[j]=sum+1;
         st.push(mp(tab[i][j],sum+1));
      }
      while(!st.empty())st.pop();
      for(int j=m;j>=1;j--){
         sum=0;
         while(!st.empty()){
            if(st.top().first>=tab[i][j]){
               sum+=st.top().second;
               st.pop();
            }
            else break;
         }
         st.push(mp(tab[i][j],sum+1));
         dpright[j]=sum+1;
      }
      memset(row,0,sizeof(row));
      cout<<i<<"\n";
      for(int j=1;j<=m;j++){
         cout<<dpleft[j]<<" "<<dpright[j]<<"\n";
      }
      int len=0;
      for(int j=1;j<=m;j++)
         row[tab[i][j]]=max(row[tab[i][j]],dpright[j]+dpleft[j]-1);
      for(int j=1;j<=i;j++)
         len=max(len,row[i-j+1]),dp[i][j]=(i-j+1)*len;
      for(int j=i;j>=1;j--)
         dp[i][j]=max(dp[i][j],dp[i-1][j]),dp[i][j]=max(dp[i][j],dp[i][j+1]);
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   input();
   solve();
   int t,x,y;
   cin>>t;
   for(int i=1;i<=t;i++){
      cin>>x>>y;
      cout<<dp[y][x]<<"\n";
   }
}
