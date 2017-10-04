#include<bits/stdc++.h>
using namespace std;
int x,y;
int r,c;
int tab[12][12];
int used[12][12];
int ax[6]={1,-1,0,0};
int bx[6]={0,0,1,-1};
void read(){
   cin>>x>>y;
   cin>>r>>c;
   for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
         char ch;
         cin>>ch;
         if(ch=='#')tab[i][j]=-1;
         else tab[i][j]=ch-'0';
      }
   }
}
int mx=0;
bool inside(int xx,int yy){
   if(0<=xx&&xx<r&&0<=yy&&yy<c)return true;
   return false;
}
void go(int br,int cx,int cy,int sum){
   //for(int i=1;i<=br;i++){
   //   cout<<" ";
   //}cout<<"cx="<<cx<<" cy="<<cy<<" sum="<<sum<<"\n";
   mx=max(mx,sum);
   used[cx][cy]=1;
   for(int i=0;i<4;i++){
      int nx,ny;
      nx=cx+ax[i]*tab[cx][cy];
      ny=cy+bx[i]*tab[cx][cy];
      if(!inside(nx,ny))continue;
      if(tab[nx][ny]==-1)continue;
      if(used[nx][ny]!=0){
         mx=max(mx,sum+tab[cx][cy]);
      }
      if(used[nx][ny]!=0)continue;
      go(br+1,nx,ny,sum+tab[cx][cy]);
      used[nx][ny]=0;
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   go(0,x,y,0);
   cout<<mx<<"\n";
}
