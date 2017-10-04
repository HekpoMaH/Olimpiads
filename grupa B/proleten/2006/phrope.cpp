#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
int sg[nmax][nmax];
int used[nmax*nmax];
void fill(int i,int j){
   for(int k=1;k<=i&&k*2<=j;k++){
      used[sg[i-k][j-2*k]]=1;
   }
}
int main(){
   int x,y;
   cin>>x>>y;
   for(int i=1;i<=x;i++){
      for(int j=1;j<=y;j++){
         memset(used,0,sizeof(used));
         fill(i,j);
         fill(j,i);
         for(int k=0;k<=nmax;k++)if(used[k]==0){sg[i][j]=k;break;}
      }
   }
   for(int i=0;i<=10;i++){
      for(int j=0;j<=i;j++){
         printf("%3d ",sg[i][j]);
      }
      cout<<"\n";
   }
   if(sg[x][y]==0)cout<<"LOSS\n";
   else cout<<"WIN\n";
}
