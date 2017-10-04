#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+9;
#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;
int n,m;
int table[nmax][nmax];
int ans[nmax][nmax];
void read(){
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         cin>>table[i][j];
         if(table[i][j]==0){
            table[i][j]=table[i-1][j]+1;
         }
         else table[i][j]=0;
      }
   }
}
void prec(){
   int dpleft[nmax],dpright[nmax];
   int row[nmax];
   stack<pii> st;
   for(int i=1;i<=n;i++){
      memset(dpleft,0,sizeof(dpleft));
      memset(dpright,0,sizeof(dpright));
      while(!st.empty())st.pop();
      for(int j=1;j<=m;j++){
         int sum=0;
         while(!st.empty()){
            pii curr=st.top();
            if(curr.fi>=table[i][j]){
               sum+=curr.se;
               st.pop();
            }
            else break;
         }
         dpleft[j]=sum+1;
         st.push(mp(table[i][j],sum+1));
      }
      while(!st.empty())st.pop();
      for(int j=m;j>=1;j--){
         int sum=0;
         while(!st.empty()){
            pii curr=st.top();
            if(curr.fi>=table[i][j]){
               sum+=curr.se;
               st.pop();
            }
            else break;
         }
         dpright[j]=sum+1;
         st.push(mp(table[i][j],sum+1));
      }
      memset(row,0,sizeof(row));
      for(int j=1;j<=m;j++){
         row[table[i][j]]=max(row[table[i][j]],dpleft[j]+dpright[j]-1);
      }
      int len=0;
      for(int j=1;j<=i;j++){
         len=max(len,row[i-j+1]);
         ans[j][i]=(i-j+1)*len;
      }
      for(int j=i;j>=1;j--){
         ans[j][i]=max(ans[j][i],ans[j][i-1]);
         ans[j][i]=max(ans[j][i],ans[j+1][i]);
      }
   }
}
void ansq(){
   int q;
   cin>>q;
   for(int i=1;i<=q;i++){
      int x,y;
      cin>>x>>y;
      cout<<ans[x][y]<<"\n";
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   prec();
   ansq();
}
