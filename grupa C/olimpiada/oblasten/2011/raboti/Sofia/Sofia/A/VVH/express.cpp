#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll INF=1500000000000000000LL;
ll p_min[50][50],p_max[50][50];
int n;
char V[50];
int main(){
  int i,j,k,l;
  //system("pause");
  cin>>V;n=strlen(V);
  for(i=0;i<n;i+=2)
   p_min[i][i]=p_max[i][i]=(V[i]-'0');
  for(l=2;l<n;l+=2){
   for(i=0;i<n;i+=2){
    j=i+l;
    if(j>=n)break;
    p_min[i][j]=+INF;
    p_max[i][j]=-INF;
    for(k=i+1;k<j;k+=2){
     switch(V[k]){
      case '+':p_min[i][j]=min(p_min[i][j],p_min[i][k-1]+p_min[k+1][j]);
               p_min[i][j]=min(p_min[i][j],p_max[i][k-1]+p_min[k+1][j]);
               p_min[i][j]=min(p_min[i][j],p_min[i][k-1]+p_max[k+1][j]);
               p_min[i][j]=min(p_min[i][j],p_max[i][k-1]+p_max[k+1][j]);

               p_max[i][j]=max(p_max[i][j],p_min[i][k-1]+p_min[k+1][j]);
               p_max[i][j]=max(p_max[i][j],p_max[i][k-1]+p_min[k+1][j]);
               p_max[i][j]=max(p_max[i][j],p_min[i][k-1]+p_max[k+1][j]);
               p_max[i][j]=max(p_max[i][j],p_max[i][k-1]+p_max[k+1][j]);
               break;
      case '-':p_min[i][j]=min(p_min[i][j],p_min[i][k-1]-p_min[k+1][j]);
               p_min[i][j]=min(p_min[i][j],p_max[i][k-1]-p_min[k+1][j]);
               p_min[i][j]=min(p_min[i][j],p_min[i][k-1]-p_max[k+1][j]);
               p_min[i][j]=min(p_min[i][j],p_max[i][k-1]-p_max[k+1][j]);

               p_max[i][j]=max(p_max[i][j],p_min[i][k-1]-p_min[k+1][j]);
               p_max[i][j]=max(p_max[i][j],p_max[i][k-1]-p_min[k+1][j]);
               p_max[i][j]=max(p_max[i][j],p_min[i][k-1]-p_max[k+1][j]);
               p_max[i][j]=max(p_max[i][j],p_max[i][k-1]-p_max[k+1][j]);
               break;
      case '*':p_min[i][j]=min(p_min[i][j],p_min[i][k-1]*p_min[k+1][j]);
               p_min[i][j]=min(p_min[i][j],p_max[i][k-1]*p_min[k+1][j]);
               p_min[i][j]=min(p_min[i][j],p_min[i][k-1]*p_max[k+1][j]);
               p_min[i][j]=min(p_min[i][j],p_max[i][k-1]*p_max[k+1][j]);

               p_max[i][j]=max(p_max[i][j],p_min[i][k-1]*p_min[k+1][j]);
               p_max[i][j]=max(p_max[i][j],p_max[i][k-1]*p_min[k+1][j]);
               p_max[i][j]=max(p_max[i][j],p_min[i][k-1]*p_max[k+1][j]);
               p_max[i][j]=max(p_max[i][j],p_max[i][k-1]*p_max[k+1][j]);
               break;
                 }
                       }
                    }
                   }
  cout<<p_min[0][n-1]<<'\n';
  return 0;
}
