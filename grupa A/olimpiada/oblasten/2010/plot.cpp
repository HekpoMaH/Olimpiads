#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
pair<double,double> A[4];
double S;
inline double dis(pair<double,double> fi,pair<double,double> se){
   return sqrt((fi.x-se.x)*(fi.x-se.x)+(fi.y-se.y)*(fi.y-se.y));
}
void solve(){
   pair<double,double> P[5],P2[5];
   pair<double,double> ans[5];
   P[1].x=100.0;
   P[2].x=100.0;
   double st=10;
   double mn=100000.0;
   P[1].y=0;
   P[2].y=0;
   while(fabs(st-0.0001)>0.0){
      for(P[1].y=max(0.0,P[1].y-10*st);P[1].y<=min(100.0,P[1].y+10*st);P[1].y+=st){
         for(P[2].y=max(0.0,P[2].y-10*st);P[2].y<=min(100.0,P[2].y+10*st);P[2].y+=st){
            if(P[1].y==P[2].y)continue;
            P[3].x=100.0+2.0*S/dis(P[1],P[2]);
            P2[1]=P[1];
            P2[2]=P[2];
            P2[3]=P[3];
            for(int i=1;i<=3;i++){
               for(int j=1;j<=3;j++){
                  for(int k=1;k<=3;k++){
                     if(i==j||i==k||j==k)continue;
                     P[3].y=A[k].y;
                     P2[3]=P[k];
                     P2[1]=P[i];
                     P2[2]=P[j];

                     if(dis(A[1],P2[1])+dis(A[2],P2[2])+dis(A[3],P2[3])<mn){
                        mn=dis(A[1],P2[1])+dis(A[2],P2[2])+dis(A[3],P2[3]);
                        ans[1]=P2[1];
                        ans[2]=P2[2];
                        ans[3]=P2[3];
                     }
                  }
               }
            }

         }
      }
      st/=10;
   }
   cout<<setiosflags(ios::fixed)<<setprecision(3)
      <<ans[1].x<<" "<<ans[1].y<<"\n"
      <<ans[2].x<<" "<<ans[2].y<<"\n"
      <<ans[3].x<<" "<<ans[3].y<<"\n";
}
int main(){
   cin>>A[1].x>>A[1].y;
   cin>>A[2].x>>A[2].y;
   cin>>A[3].x>>A[3].y;
   S=(A[2].x-A[1].x)*(A[3].y-A[1].y)-(A[2].y-A[1].y)*(A[3].x-A[1].x);
   S=fabs(S);
   solve();
}
