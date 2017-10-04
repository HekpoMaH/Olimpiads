#include<bits/stdc++.h>
using namespace std;
const double eps=1e-12;
struct vec{
   double x,y;
   vec(){}
   vec(double _x,double _y){
      x=_x;
      y=_y;
   } 
   vec operator-(vec b) { return vec(x-b.x, y-b.y); }
};
double cp(vec f,vec s){
   return f.x*s.y-s.x*f.y;
}
inline bool eq(double f,double s){
   return fabs(f-s)<eps;
}
int n;
vec A,B,C;
vector<vec> As,Bs,Cs;
int dp[100000],sofs;
void read(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
      if(A.x!=B.x&&A.x!=C.x&&B.x!=C.x&&A.y!=B.y&&A.y!=C.y&&B.y!=C.y)continue;
      vec AB=B-A;
      vec AC=C-A;
      //AB.x=B.x-A.x;
      //AB.y=B.y-A.y;
      //AC.x=C.x-A.x;
      //AC.y=C.y-A.y;
      double s=fabs(cp(AB,AC))/2;
      if(!eq(s,floor(s+eps/2)))continue;
      sofs+=s;
      As.push_back(A);
      Bs.push_back(B);
      Cs.push_back(C);
   }
}
void makedp(){
   n=As.size();
   dp[0]=1;
   for(int i=0;i<n;i++){
      vec AB=Bs[i]-As[i];
      vec AC=Cs[i]-As[i];
      int s=abs(cp(AB,AC))/2;
      for(int j=sofs;j>=0;j--){
         if(j>=s&&dp[j-s]!=0)dp[j]=1;
      }
   }
   int mn=1e6,mn1,mn2;
   for(int i=0;i<=sofs;i++){
      if(dp[i]!=0){
         int s1=i,s2=sofs-i;
         if(abs(s1-s2)<mn){
            mn=abs(s1-s2);
            mn1=s1;
            mn2=s2;
         }
      }
   }
   if(mn1>mn2)swap(mn1,mn2);
   cout<<mn1<<" "<<mn2<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   makedp();
}

