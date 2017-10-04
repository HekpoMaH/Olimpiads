#include<bits/stdc++.h>
using namespace std;
const int nmax=444;
const int inf=1e9;
int n,m;
int r[nmax];
int c[nmax];
int z[nmax][nmax];
int tab[nmax][nmax];
int flow[nmax][nmax];
int source,sink;
int used[nmax],pred[nmax];
int fl=true;
void buildgraph(){
   for(int i=1;i<=m;i++){
      for(int j=1;j<=n;j++){
         if(z[i][j]==-1){
            tab[i][m+j]=inf;
         }
      }
   }
   for(int i=1;i<=m;i++){
      tab[0][i]=r[i];
   }
   for(int i=1;i<=n;i++){
      tab[m+i][n+m+1]=c[i];
   }
}
void bfs(){
   queue<int> q;
   q.push(0);
   used[0]=1;
   pred[0]=-1;
   while(!q.empty()){
      int curr=q.front();
      q.pop();
      for(int i=0;i<=n+m+1;i++){
         if(used[i]==0&&tab[curr][i]>0){
            used[i]=1;
            q.push(i);
            pred[i]=curr;
         }
      }
   }
   //for(int i=n+m+1;i!=-1;i=pred[i]){
   //   if(pred[i]!=-1)cout<<i<<" "<<pred[i]<<" "<<tab[pred[i]][i]<<"\n";
   //}
   
   if(used[n+m+1]==1)fl=1;
}
void solve(){
   int mxflow=0;
   while(fl){
      fl=false;
      memset(used,0,sizeof(used));
      memset(pred,-1,sizeof(pred));
      bfs();
      if(!fl)break;
      int mn=inf;
      for(int i=m+n+1;i!=-1;i=pred[i]){
         if(pred[i]!=-1){
            mn=min(mn,tab[pred[i]][i]);
         }
      }
      //cout<<mn<<"\n";
      for(int i=m+n+1;i!=-1;i=pred[i]){
         if(pred[i]!=-1){
            tab[i][pred[i]]+=mn;
            tab[pred[i]][i]-=mn;
            flow[i][pred[i]]-=mn;
            flow[pred[i]][i]+=mn;
         }
      }
      mxflow+=mn;
   }
   //if(mxflow==0){
   //   cout<<"-1\n";
   //   exit(0);
   //}
   for(int i=1;i<=m;i++){
      int sum=0;
      for(int j=1;j<=n;j++){
         if(z[i][j]!=-1){
            //cout<<z[i][j]<<" ";
            sum+=z[i][j];
         }
         else sum+=flow[i][m+j];//cout<<flow[i][m+j]<<" ";
      }
      if(sum>r[i]){
      }
      //cout<<r[i]<<" "<<sum<<"\n";
      //cout<<"\n";
   }
   //for(int j=1;j<=n;j++){
   //   int sum=0;
   //   for(int i=1;i<=m;i++){
   //      if(z[i][j]!=-1){
   //         //cout<<z[i][j]<<" ";
   //         sum+=z[i][j];
   //      }
   //      else sum+=flow[i][m+j];//cout<<flow[i][m+j]<<" ";
   //   }
   //   if(sum>c[j]){
   //      cout<<"-1\n";
   //      exit(0);
   //   }
   //   //cout<<"\n";
   //}
   for(int i=1;i<=m;i++){
      for(int j=1;j<=n;j++){
         if(z[i][j]!=-1){
            cout<<z[i][j]<<" ";
         }
         else cout<<flow[i][m+j]<<" ";
      }
      cout<<"\n";
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>m>>n;
   for(int i=1;i<=m;i++){
      cin>>r[i];
   }
   for(int i=1;i<=n;i++){
      cin>>c[i];
   }
   for(int i=1;i<=m;i++){
      for(int j=1;j<=n;j++){
         cin>>z[i][j];
         if(z[i][j]!=-1){
            c[j]-=z[i][j];
            if(c[j]<0){
               cout<<"-1\n";
               exit(0);
            }
            r[i]-=z[i][j];
            if(r[i]<0){
               cout<<"-1\n";
               exit(0);
            }
         }
      }
   }
   buildgraph();
   solve();
}

