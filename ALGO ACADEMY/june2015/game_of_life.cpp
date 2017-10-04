#include<iostream>
using namespace std;
const int nmax=129;
const int dx[9]={1,-1,0,0,1,1,-1,-1};
const int dy[9]={0,0,1,-1,1,-1,1,-1};
bool grid[nmax][nmax];
int n;
int h,w;
bool nwgrid[nmax][nmax];
inline bool IsIn(int x,int y){
   return x>=1&&x<=h&&y>=1&&y<=w;
}
inline void donext(){
   int i,j,k;
   for(j=1;j<=w;j++){
      for(i=1;i<=h;i++){
         nwgrid[i][j]=grid[i][j];
      }
   }
   for(j=1;j<=w;j++){
      for(i=1;i<=h;i++){
         int liv=0;
         if(IsIn(i+1,j)&&grid[i+1][j]==true)liv++;
         if(IsIn(i,j+1)&&grid[i][j+1]==true)liv++;
         if(IsIn(i-1,j)&&grid[i-1][j]==true)liv++;
         if(IsIn(i,j-1)&&grid[i][j-1]==true)liv++;
         if(IsIn(i+1,j+1)&&grid[i+1][j+1]==true)liv++;
         if(IsIn(i+1,j-1)&&grid[i+1][j-1]==true)liv++;
         if(IsIn(i-1,j+1)&&grid[i-1][j+1]==true)liv++;
         if(IsIn(i-1,j-1)&&grid[i-1][j-1]==true)liv++;
         if(liv==2){
            nwgrid[i][j]=grid[i][j];
         }
         if(liv==3){
            nwgrid[i][j]=true;
         }
         if(liv<2||liv>3){
            nwgrid[i][j]=false;
         }
      }
   }
   for(j=1;j<=w;j++){
      for(i=1;i<=h;i++){
         grid[i][j]=nwgrid[i][j];
         //cout<<grid[i][j];
      }
      //cout<<"\n";
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   cin>>h>>w;
   int i,j;
   for(i=1;i<=h;i++){
      for(j=1;j<=w;j++){
         cin>>grid[i][j];
      }
   }
   for(i=1;i<=n;i++){
      donext();
   }
   //cout<<"BASI\n";
   int br=0;
   for(j=1;j<=w;j++){
      for(i=1;i<=h;i++){
         if(grid[i][j]==true)br++;
      }
   }
   cout<<br<<"\n";
}
