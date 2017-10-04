/*
TASK: maze
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
#define lgn 15
#define SIZE 20010
int n;
vector<int> fo[SIZE];
int max_d[SIZE],depth[SIZE];
int go_down[SIZE][lgn+1],go_up[SIZE][lgn+1];
int MD1[SIZE],MD2[SIZE];
void dfs(int vr,int par){
  if(par!=-1)fo[vr].erase(find(fo[vr].begin(),fo[vr].end(),par));
  if(par!=-1)depth[vr]=depth[par]+1;
  // setting go_up
  go_up[vr][0]=par;
  for(int i=1;i<=lgn;++i){
   int to=go_up[vr][i-1];if(to==-1)break;
   go_up[vr][i]=go_up[to][i-1];
                         }
  // </end>
  int md1=-1,md2=-1;
  for(int i=0;i<fo[vr].size();++i){
   int to=fo[vr][i];
   dfs(to,vr );
   if(md2==-1 || max_d[to]>max_d[md2]){
    md2=to;
    if(md1==-1 || max_d[md1]<max_d[md2])swap(md1,md2);
                                      }
                                  }
  MD1[vr]=md1;MD2[vr]=md2;
  // SETTING max_d
  if(md1!=-1)max_d[vr]=1+max_d[md1];
  // setting go_down
  go_down[vr][0]=md1;
  for(int i=1;i<=lgn;++i){
   int to=go_down[vr][i-1];if(to==-1)break;
   go_down[vr][i]=go_down[to][i-1];
                         }
}
int climb_up(int vr,int how){
  int lg=lgn;
  while(how>0){
   if(how<(1<<lg)){--lg;continue;}
   else{how-=(1<<lg);vr=go_up[vr][lg];}
              }
  return vr;
}
int climb_down(int vr,int how){
  int lg=lgn;
  while(how>0){
   if(how<(1<<lg)){--lg;continue;}
   else{how-=(1<<lg);vr=go_down[vr][lg];}
              }
  return vr;
}
int LP_V[SIZE],LP_L[SIZE],LP_GO[SIZE];
void dfs1(int vr,int best_v,int best_l,int razkl){
  LP_V[vr]=vr;LP_L[vr]=max_d[vr];LP_GO[vr]=MD1[vr];
  if(best_l+depth[vr]+1 >LP_L[vr]){
   LP_L[vr]=best_l+depth[vr]+1;
   LP_V[vr]=best_v;
   LP_GO[vr]=razkl;
                                  }
  for(int i=0;i<fo[vr].size();++i){
   int to=fo[vr][i],use;
   if(to==MD1[vr])use=MD2[vr];
   else use=MD1[vr];
   if(use!=-1){
    if(best_l<=max_d[use]-depth[vr])dfs1(to,vr,max_d[use]-depth[vr],use);
    else dfs1(to,best_v,best_l,razkl);
              }
   else{
    if(best_l< -depth[vr])dfs1(to,vr,-depth[vr],-1);
    else dfs1(to,best_v,best_l,razkl);
       }
                                  }
}
int QUERRY(int vr,int d){
  if(LP_L[vr]<d)return 0;
  int root=LP_V[vr];
  if(depth[vr]-depth[root]>=d)return climb_up(vr,d)+1;
  d-=(1+depth[vr]-depth[root]);
  return climb_down(LP_GO[vr],d)+1;
}
int main(){
  int i,j,k,l;
  scanf("%d",&n);
  for(i=0;i<n;++i){
   int Q;scanf("%d",&Q);
   while(Q-- >0){
    scanf("%d",&l);--l;
    fo[i].push_back(l);
                }
                  }
  dfs(0,-1);
  dfs1(0,-1,-INF,-1);
  int _Q;scanf("%d",&_Q);
  while(_Q-- >0){
   int v,d;scanf("%d%d",&v,&d);--v;
   printf("%d\n",QUERRY(v,d));
                }
  return 0;
}
