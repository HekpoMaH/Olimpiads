#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
const double eps=1e-9;
int n;
double a[maxn][maxn],b[maxn];
double a2[maxn][maxn];
inline bool eq(double x,double y){
   return fabs(x-y)<eps;
}
void solve(){
   bool hassol=true;
   for(int j=1;j<=n;j++){
      double todiv=-1.0;
      int i=j;
      for(i=j;i<=n;i++){
         if(!eq(a[i][j],0.0)){
            todiv=a[i][j];
            for(int k=1;k<=n+1;k++){
               a[i][k]/=todiv;
            }
            break;
         }
      }
      if(eq(todiv,-1.0)){
         hassol=false;
         continue;
      }
      for(int j1=1;j1<=n+1;j1++)swap(a[i][j1],a[j][j1]);
      for(int i1=1;i1<=n;i1++){
         if(i1==i)continue;
         todiv=a[i1][j];
         for(int j1=j;j1<=n+1;j1++)a[i1][j1]-=todiv*a[i][j1];
      }
   }
   if(hassol==false){
      for(int i=1;i<=n;i++){
         double has0=true;
         for(int j=1;j<=n;j++)if(a[i][j]!=0)has0=false;
         if(a[i][n+1]!=0&&has0==true){
            cout<<"nqma re6enie\n";
            return;
         }
      }
      cout<<"bezbroi mn\n";
      return;
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cout<<a[i][j]<<" ";
      }
      cout<<"| "<<a[i][n+1]<<"\n";
   }
}
void chek(){
   for(int i=1;i<=n;i++){
      //for(int j=1;j<=n;j++)cout<<a2[i][j]<<" ";cout<<"\n";
      cout<<i<<"th equation->";
      double s=0;
      for(int j=1;j<=n;j++)s+=a[j][n+1]*a2[i][j];
      cout<<s<<"\n";
   }
}
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n+1;j++)cin>>a[i][j];
   }
   memcpy(a2,a,sizeof(a));
   solve();
   //chek();
}
