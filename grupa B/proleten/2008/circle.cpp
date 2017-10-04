#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
struct vec{
   int x,y;
   vec(){}
   vec(int _x,int _y){
      x=_x;
      y=_y;
   }
   vec operator-(vec b){
      return vec(x-b.x,y-b.y);
   }
   int len2(){
      return x*x+y*y;
   }
};
vec p[nmax];
int r[nmax];
int n;
vector<int> g[nmax];
int used[nmax];
void readmake(){
   cin>>n;
   for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y>>r[i];
   for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
         vec AB=p[j]-p[i];
         int a=abs(r[j]-r[i]);
         int b=r[i]+r[j];
         if(a*a<AB.len2()&&AB.len2()<b*b){
            g[i].push_back(j);
            g[j].push_back(i);
         }
      }
   }
}
void bfs(){
   queue<int> q;
   q.push(1);
   used[1]=1;
   while(!q.empty()){
      int cur=q.front();//cur moje i s 1va bukva k
      q.pop();
      for(int i=0;i<g[cur].size();i++){
         if(used[g[cur][i]]==0){
            q.push(g[cur][i]);
            used[g[cur][i]]=used[cur]+1;
         }
      }
   }
   cout<<used[n]-1<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   readmake();
   bfs();
}
