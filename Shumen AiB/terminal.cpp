#include<bits/stdc++.h>
using namespace std;
const int nmax=209;
int row[nmax][nmax],col[nmax][nmax];
int a[nmax][nmax];
int n,m,k;
void doa(int r,int c,char d,int v){
   int beg,end;
   if(d=='U'){
      beg=1;
      end=r;
      col[c][beg]+=v;
      col[c][end+1]-=v;
      return;
   }

   if(d=='D'){
      beg=r;
      end=n;
      col[c][beg]+=v;
      col[c][end+1]-=v;
      return;
   }
   
   if(d=='L'){
      beg=1,end=c;
      row[r][beg]+=v;
      row[r][end+1]-=v;
      return;
   }
   
   if(d=='R'){
      beg=c,end=m;
      row[r][beg]+=v;
      row[r][end+1]-=v;
      return;
   }
   //this was bad code-duplicaton
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m>>k;
   for(int i=1;i<=k;i++){
      char ch;
      int r,c,v;
      char d;
      cin>>ch;
      if(ch=='A'){
         cin>>r>>c>>d>>v;
         doa(r,c,d,v);
      }
      if(ch=='B'){
         int r1,r2,c1,c2;
         cin>>r1>>c1>>r2>>c2>>d>>v;
         for(int i1=r1;i1<=r2;i1++){
            for(int j1=c1;j1<=c2;j1++){
               doa(i1,j1,d,v);
            }
         }
      }
   }
   for(int i=1;i<=n;i++){
      int sum=0;
      for(int j=1;j<=m;j++){
         sum+=row[i][j];
         a[i][j]=sum;
      }
   }
   for(int j=1;j<=m;j++){
      int sum=0;
      for(int i=1;i<=n;i++){
         sum+=col[j][i];
         a[i][j]+=sum;
      }
   }
   for(int i=1;i<=n;i++){
      int sum=0;
      for(int j=1;j<=m;j++){
         cout<<a[i][j]<<" ";
      }
      cout<<endl;
   }
}
