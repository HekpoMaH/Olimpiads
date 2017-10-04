#include<bits/stdc++.h>
using namespace std;
const int nmax=709;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
int n,m;
int table[nmax][nmax][2];
int used[nmax*nmax];
struct karti4ka{
   int x[3],y[3],z[3];
   karti4ka(){}
   karti4ka(int x1,int y1,int z1,int x2,int y2,int z2){
      x[1]=x1;y[1]=y1;z[1]=z1;
      x[2]=x2;y[2]=y2;z[2]=z2;
   }
};
karti4ka cards[nmax*nmax];
bool leaveIt[nmax*nmax];
int cbr=0;
vector<int> ans;
bool isIn(int x,int y){
   return 1<=x&&x<=n&&1<=y&&y<=m;
}
void bfs(karti4ka curr,bool leave){
   queue<karti4ka> q;
   used[table[curr.x[1]][curr.y[1]][curr.z[1]]]=1;
   leaveIt[table[curr.x[1]][curr.y[1]][curr.z[1]]]=leave;
   q.push(curr);
   while(!q.empty()){
      curr=q.front();
      q.pop();
      //cout<<curr.x[1]<<" "<<curr.y[1]<<" "<<curr.z[1]<<" "<<(table[curr.x[1]][curr.y[1]][curr.z[1]])<<" "
         //<<leaveIt[table[curr.x[1]][curr.y[1]][curr.z[1]]]<<"\n";
      if(leaveIt[ table[curr.x[1]][curr.y[1]][curr.z[1]] ]){
         if(curr.z[1]==1||curr.z[2]==1)ans.push_back(table[curr.x[1]][curr.y[1]][curr.z[1]]);
      }
      for(int I=1;I<=2;I++){
         int layr=1;
         int ni=curr.x[I];
         int nj=curr.y[I];
         if(used[table[ni][nj][layr]]==0){
            for(int i=1;i<=2;i++)used[table[ni][nj][layr]]=1;
            leaveIt[table[ni][nj][layr]]=leaveIt[ table[curr.x[1]][curr.y[1]][curr.z[1]] ]^1;
            q.push(cards[table[ni][nj][layr]]);
         }
      }
   }
}
void input(){
   cin>>n>>m;
   for(int k=0;k<=1;k++){
      for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
            cin>>table[i][j][k];
         }
      }
   }
   for(int k=0;k<=1;k++){
      for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
            for(int kd=0;kd<3;kd++){
               for(int layr=0;layr<=1;layr++){
                  int ni=i+dx[kd];
                  int nj=j+dy[kd];
                  if(!isIn(ni,nj))continue;
                  if(used[table[i][j][k]]==0&&table[i][j][k]==table[ni][nj][layr]){
                     cards[table[i][j][k]]=karti4ka(i,j,k,ni,nj,layr);
                     used[table[i][j][k]]=1;
                     cbr++;
                  }
               }
            }
         }
      }
   }
   //for(int i=1;i<=cbr;i++){
   //   for(int j=1;j<=2;j++)cout<<cards[i].x[j]<<" "<<cards[i].y[j]<<" "<<cards[i].z[j]<<"\n";
   //   cout<<"\n";
   //}
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   input();
   memset(used,0,sizeof(used));
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(!used[table[i][j][1]])bfs(cards[table[i][j][1]],1);
      }
   }
   if(ans.size()==cbr/2){
      cout<<"YES"<<"\n";
      for(int i=0;i<(int)ans.size();i++){
         cout<<ans[i]<<"\n";
      }
   }
   else cout<<"NO\n";
}
