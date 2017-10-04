#include<bits/stdc++.h>
using namespace std;
const int nmax=109;
const double eps=1e-12;
int N,M,n;
int to[nmax];
double a[nmax][nmax];
int S,L;
bool eq(double f,double s){
   return fabs(f-s)<eps;
}
void read(){
   cin>>N>>M>>S>>L;
   n=N*M;
   for(int i=1;i<=n;i++)to[i]=i;
   for(int i=1;i<=S+L;i++){
      int x,y;
      cin>>x>>y;
      to[x]=y;
   }
}
void makea(){
   a[n][n+1]=0.0;
   a[n][n]=1.0;
   for(int i=n-1;i>=1;i--){
      a[i][n+1]=-1.0;
      a[i][n]=-1.0;
      for(int j=1;j<=6;j++){
         if(i+j>n)a[i][i]+=1.0/6.0;
         else{
            a[i][to[i+j]]+=1.0/6.0;
         }
      }
   }
}
void gauss(){
   for(int j=1;j<=n;j++){
      double todiv=-1.0;
      int i;
      for(i=1;i<=n;i++){
         if(!eq(a[i][j],0.0)){
            todiv=a[i][j];
            break;
         }
      }
      if(eq(todiv,-1.0))assert(false);
      for(int j1=1;j1<=n+1;j1++){
         swap(a[i][j],a[i][j1]);
      }
      for(int i1=1;i1<=n;i1++){
         if(i1==i)continue;
         todiv=a[i1][j];
         for(int j1=1;j1<=n+1;j1++){
           a[i1][j1]-=todiv*a[i][j1]; 
         }
      }
   }
   cout<<setiosflags(ios::fixed)<<setprecision(3)<<a[1][n+1]<<"\n";
}
int main(){
   read();
   makea();
   gauss();
}
