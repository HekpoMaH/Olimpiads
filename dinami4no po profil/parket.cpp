#include<bits/stdc++.h>
using namespace std;
const int mmax=1<<10;
int d[mmax][mmax];
int n,m;
bool chek(int x,int y){
   for(int i=0;i<m;i++){
      if(y&(1<<i)){
         if(x&(1<<i))return false;
      }
      else{

      }
   }
}
void maked(){
   for(int i=0;i<mmax;i++){
      for(int j=0;j<mmax;j++){
         if(chek(i,j))d[i][j]=1;
      }
   }
}
int main(){
   cin>>n>>m;
   maked();
}
