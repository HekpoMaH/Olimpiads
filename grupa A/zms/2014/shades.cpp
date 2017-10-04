#include<bits/stdc++.h>
using namespace std;
const int nmax=509;
#define mp make_pair
int used[nmax][nmax][6];
short int prev[nmax][nmax][6];
int n,m;
char grid[nmax][nmax];
int dx[6]={0,1,-1,0,0};
int dy[6]={0,0,0,-1,1};
typedef pair<pair<int,int>,int> pii;
void read(){
   cin>>n>>m;
   cin.get(grid[0][0]);
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         cin.get(grid[i][j]);
      }
      cin.get(grid[0][0]);
   }
}
void solve(){
   int x1,x2,y1,y2;
   cin>>x1>>y1>>x2>>y2;
   memset(used,0,sizeof(used));
   memset(prev,-1,sizeof(prev));
   queue<pii> q;
   q.push(mp(mp(x1,y1),grid[x1][y1]=='W' ? 4 : 2));
   used[x1][y1][grid[x1][y1]=='W' ? 4 : 2]=1;
   while(!q.empty()){
      pii cur=q.front();
      q.pop();
      //cout<<cur.first.first<<" "<<cur.first.second<<" "<<cur.second<<"\n";
      for(int i=1;i<=4;i++){
         int nx=cur.first.first+dx[i],ny=cur.first.second+dy[i];
         int nbr=cur.second+ (grid[nx][ny]=='W' ? 1 : -1);
         if(!(nbr>=1&&nbr<=5))continue;
         if(!(nx>=1&&nx<=n))continue;
         if(!(ny>=1&&ny<=m))continue;
         if(used[nx][ny][nbr]!=0)continue;
         //cout<<"nx="<<nx<<" ny="<<ny<<" nbr="<<nbr<<" kletka="<<grid[nx][ny]<<"\n";
         used[nx][ny][nbr]=used[cur.first.first][cur.first.second][cur.second]+1;
         prev[nx][ny][nbr]=i;
         q.push(mp(mp(nx,ny),nbr));
      }
   }
   if(used[x2][y2][3]!=0)cout<<used[x2][y2][3]<<" ";
   else{
      cout<<-1<<"\n";
      return;
   }
   int br=3;
   stack<char> st;
   while(prev[x2][y2][br]!=-1){
      if(prev[x2][y2][br]==1){
         st.push('D');
         br+= grid[x2][y2]=='W' ? -1 : 1;
         x2--;
      }
      else if(prev[x2][y2][br]==2){
         st.push('U');
         br+= grid[x2][y2]=='W' ? -1 : 1;
         x2++;
      }
      else if(prev[x2][y2][br]==3){
         st.push('L');
         br+= grid[x2][y2]=='W' ? -1 : 1;
         y2++;
      }
      else if(prev[x2][y2][br]==4){
         st.push('R');
         br+= grid[x2][y2]=='W' ? -1 : 1;
         y2--;
      }
   }
   while(!st.empty()){
      cout<<st.top();
      st.pop();
   }
   cout<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   int t;
   cin>>t;
   while(t--){
      solve();
   }
}
