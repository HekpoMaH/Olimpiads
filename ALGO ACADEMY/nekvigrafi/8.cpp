#include<bits/stdc++.h>
using namespace std;
const int nmax=1509;
#define mp make_pair
int used[nmax][nmax];
int n,m;
int r,c;
int ax[10]={-2,-2,-1,1,2,2,1,-1};
int bx[10]={-1,1,2,2,1,-1,-2,-2};
bool inside(int x,int y){
   if(0<=x&&x<n&&0<=y&&y<m)return true;
   return false;
}
int main(){
   cin>>n>>m;
   cin>>r>>c;
   queue<pair<int,int> > q;
   q.push(mp(r,c));
   used[r][c]=1;
   while(!q.empty()){
      int cr,cc;
      cr=q.front().first;
      cc=q.front().second;
      q.pop();
      for(int i=0;i<8;i++){
         int nr,nc;
         nr=cr+ax[i];
         nc=cc+bx[i];
         if(inside(nr,nc)&&used[nr][nc]==0){
            q.push(make_pair(nr,nc));
            used[nr][nc]=used[cr][cc]+1;
         }
      }
   }
   for(int i=0;i<n;i++){
      cout<<used[i][m/2]<<"\n";
   }
}
