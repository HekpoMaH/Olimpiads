#include<iostream>
#include<string>
#include<stack>
#include<cstring>
using namespace std;
int dx[6]={0,1,-1,0,0};
int dy[6]={0,0,0,1,-1};
int used[109][109];
int tab[109][109];
int n,m;
void dfs(int x,int y){
   cout<<x+1<<" "<<y+1<<"\n";
   used[x][y]=1;
   for(int i=1;i<=4;i++){
      if(!(x+dx[i]>=0&&x+dx[i]<n&&y+dy[i]>=0&&y+dy[i]<m))continue;
      if(used[x+dx[i]][y+dy[i]]==0&&tab[x+dx[i]][y+dy[i]]==1){
         dfs(x+dx[i],y+dy[i]);
      }
   }
}
void solve(){
   string s[109];
   memset(tab,0,sizeof(tab));
   memset(used,0,sizeof(used));
   cin>>n>>m;
   for(int i=0;i<n;i++){
      cin>>s[i];
   }
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         for(int k=1;k<=4;k++){
            for(int k2=1;k2<=4;k2++){
               if(dx[k]==0&&dy[k2]==0)continue;
               if(!(i+dx[k]>=0&&i+dx[k]<n&&j+dy[k2]>=0&&j+dy[k2]<m))continue;
               if(s[i+dx[k]][j+dy[k2]]=='.'&&s[i][j]!='.')tab[i+dx[k]][j+dy[k2]]=1;
            }
         }
      }
   }
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(tab[i][j]==1){
           dfs(i,j); 
           return;
        }
      }
   }

}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t=1;
   while(t--){
      solve();
   }
}
