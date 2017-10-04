#include<bits/stdc++.h>
using namespace std;
class point{
   private:
      int x,y;
   public:
      void read(){
         cin>>x>>y;
      }
      void outp();
      void setx(int k){
         x=k;
      }
      void sety(int k){
         y=k;
      }
      int getx(){
         return x;
      }
      int gety(){
         return y;
      }
      void inc(int k){
         setx(x+k);
         sety(y+k);
      }
      int sqrDist(point p){
         return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);
      }
      point(){x=y=0;}
      point(int _x,int _y){
         x=_x;
         y=_y;
      }
      point(const point &p){
         x=p.x;
         y=p.y;
      }
      ~point(){}
};
void point::outp(){
   cout<<"("<<x<<","<<y<<")\n";
}
point A(6,5),B(A);
int main(){
   point *p;
   p=new point(3,9);
   p->outp();
   A.read();
   B.read();
   cout<<A.sqrDist(B)<<"\n";
}
