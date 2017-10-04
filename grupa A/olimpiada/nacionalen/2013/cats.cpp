#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int nmax=32;
const int emax=1<<15;
struct EDGE{
   int to;
   bool left;
   int prev;
};
EDGE edge[emax];
int edgesz=2;
int first[1<<11];
bool used[1<<11];
bool cat[nmax][nmax];

//const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m;
void addedge(int from,int to){
   edge[edgesz].to=to;
   edge[edgesz].left=true;
   edge[edgesz].prev=first[from];
   first[from]=edgesz;
   edgesz++;
   edge[edgesz].to=from;
   edge[edgesz].left=false;
   edge[edgesz].prev=first[to];
   first[to]=edgesz;
   edgesz++;
}
void adddir(int i1,int j1,int i2,int j2){
   addedge(2*(i1*m+j1)+1,2*(i2*m+j2));
}
int construct(){
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(i>0&&i+1<n&&j>0&&j+1<m){
            adddir(i,j,i-1,j);
            adddir(i,j,i,j-1);
            adddir(i,j,i+1,j);
            adddir(i,j,i,j+1);
         }
         else addedge(2*(i*m+j)+1,2047);
         if(cat[i][j])addedge(2*m*n,2*(i*m+j)+1);
         else addedge(2*(i*m+j), 2*(i*m+j)+1);
      }
   }
   return 2*n*m;
}
bool findflow(int loc){
   used[loc]=1;
   if(loc==2047)return true;
   for(int i=first[loc];i;i=edge[i].prev){
      if(used[edge[i].to]||!edge[i].left)continue;
      if(findflow(edge[i].to)){
         edge[i].left=0;
         edge[i^1].left=1;
         return true;
      }
   }
   return false;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=0;i<n;i++){
      string s;
      cin>>s;
      m=s.size();
      for(int j=0;j<m;j++){
         cat[i][j]= s[j]=='1';
      }
   }
   int k=construct();
   int i=0;
   while(findflow(k)){
      memset(used,0,sizeof(used));
      i++;
   }
   cout<<i<<"\n";
}
