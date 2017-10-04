#include<bits/stdc++.h>
using namespace std;
const int nmax=3009;
const int mmax=30009;
int g[nmax][nmax];
int n,m;
int upar[nmax][nmax];
int udec[nmax][nmax];
vector<int> pars[nmax];
vector<int> deca[nmax];
set<int> spars[nmax];
set<int> sdeca[nmax];
set<pair<int,int> >calced;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      int x,y;
      cin>>x>>y;
      g[x][y]=1;
      upar[y][x]++;
      udec[x][y]++;
      deca[x].push_back(y);
      pars[y].push_back(x);
      sdeca[x].insert(y);
      spars[y].insert(x);
   }
   long long br=0;
   long long br2;
   for(int i=1;i<=n;i++){
      for(int j=i;j<=n;j++){
         if(i==j)continue;
         //if(g[i][j]==1||g[j][i]==1)continue;
         br2=0;
         for(int k=0;k<pars[i].size();k++){
            if(upar[j][pars[i][k]]==1)br2++;
         }
         for(int k=0;k<deca[i].size();k++){
            if(udec[j][deca[i][k]]==1){
               if(upar[j][deca[i][k]]!=0||upar[i][deca[i][k]]!=0)br+=br2-1;
               else br+=br2;
            }
         }
      }
   }
   cout<<br<<"\n";
}
