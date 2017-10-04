#include<bits/stdc++.h>
using namespace std;
struct vec{
   double x,y;
   vec(){}
   vec(double _x,double _y){
      x=_x;
      y=_y;
   }
   vec operator-(vec B){
      return vec(x-B.x,y-B.y);
   }
   vec operator+(vec B){
      return vec(x+B.x,y+B.y);
   }
   double cross(vec B){
      return x*B.y-y*B.x;
   }
};
vec A,B,C;
bool check(vec D){
   vec AB=B-A;
   vec AD=D-A;
   vec BC=C-B;
   vec BD=D-B;
   vec CA=A-C;
   vec CD=D-C;
   //cout<<"\n";
   //cout<<AB.cross(AD)<<" "<<BC.cross(BD)<<" "<<CA.cross(CD)<<"\n";
   //cout<<"\n";
   if(AB.cross(AD)>=0.0&&BC.cross(BD)>=0.0&&CA.cross(CD)>=0.0)return true;
   if(AB.cross(AD)<=0.0&&BC.cross(BD)<=0.0&&CA.cross(CD)<=0.0)return true;
   return false;
}
int main(){
   cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
   vec D;
   int n;
   cin>>n;
   int br=0;
   for(int i=1;i<=n;i++){
      cin>>D.x>>D.y;
      if(check(D))br++;
   }
   cout<<br<<"\n";
}
