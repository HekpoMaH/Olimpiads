#include<bits/stdc++.h>
using namespace std;
struct vec{
   int x,y;
   vec(){}
   vec(int _x,int _y){
      x=_x;
      y=_y;
   }
   vec operator-(vec p){
      return vec(x-p.x,y-p.y);
   }
   vec operator*(vec p){
      return vec(p.x+x,p.y+y);
   }
   int len2(){
      return x*x+y*y;
   }
};
int dot(vec a,vec b){
   return a.x*b.x+a.y*b.y;
}
vec P1,P2,giv;
int a,b;
set<int> s;
int main(){
   cin>>P1.x>>P1.y>>P2.x>>P2.y>>a>>b;
   giv=P2-P1;
   int br=0;
   for(int i=1;i<a;i++){
      for(int j=1;j<b;j++){
         for(int i1=1;i1<a;i1++){
            for(int j1=1;j1<b;j1++){
               if((i==i1&&j==j1))continue;
               vec N1,N2;
               N1.x=i;N1.y=j;
               N2.x=i1;N2.y=j1;
               vec nv=N2-N1; 
               if(dot(nv,giv)==0)br++,s.insert(nv.len2());
            }
         }
      }
   }
   cout<<br/2<<" "<<s.size()<<"\n";
}
