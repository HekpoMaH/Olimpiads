#include<bits/stdc++.h>
using namespace std;
int bes[20][20];
int el[20][20];
int a,b;
vector<int> g[20];
int n,m;
int haha[100009];
int haha2[100009];
void gobes(int node,int time){

   if(node==n){
      haha[time]=1;
      return;
   }
   for(int i=0;i<g[node].size();i++){
      gobes(g[node][i],time+bes[node][g[node][i]]);
   }
}
void goel(int node,int time){
   if(node==n){
      haha2[time]=1;
      return;
   }
   for(int i=0;i<g[node].size();i++){
      goel(g[node][i],time+el[node][g[node][i]]);
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   ifstream fin("meeting.in");
   ofstream fout("meeting.out");
   fin>>n>>m;
   for(int i=1;i<=m;i++){
      int x,y;
      fin>>x>>y;
      fin>>bes[x][y]>>el[x][y];
      g[x].push_back(y);
   }
   gobes(1,0);
   goel(1,0);
   for(int i=1;i<=100000;i++){
      if(haha[i]==1&&haha2[i]==1){
         fout<<i<<"\n";
         return 0;
         //exit(0);
      }
   }
   fout<<"IMPOSSIBLE\n";
}
