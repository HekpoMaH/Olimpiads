#include<bits/stdc++.h>
using namespace std;
typedef double type;
const double pi = acos(-1.0);
const int nmax=100;
struct vec {
  type x, y;
  vec(){}
  vec(type _x,type _y){
     x=_x;
     y=_y;
  }
  vec operator+(vec b){
     return vec(x+b.x,y+b.y);
  }
  vec operator-(vec b){
     return vec(x-b.x,y-b.y);
  }
  vec operator*(type k){
     return vec(k*x,k*y);
  }
  type len2(){
     return x*x+y*y;
  }
  vec rot(double alpha){
	return vec(x*cos(alpha)-y*sin(alpha),x*sin(alpha)+y*cos(alpha));
  }
  double len(){
     return sqrt(this->len2());
  }
};
type dot(vec u,vec v) {
  return u.x*v.x + u.y*v.y;
}
type cross(vec u, vec v) {
  return u.x*v.y - v.x*u.y;
}
vec ul[nmax];
int n;
int idx1,idx2;
type spicane[nmax][nmax];
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      vec A,B;
      cin>>A.x>>A.y>>B.x>>B.y;
      ul[i]=B-A;
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         if(i==j)continue;
         if(cross(ul[i],ul[j])!=0){
            spicane[i][j]=asin(cross(ul[i],ul[j])/(ul[i].len()*ul[j].len()))*180/pi;
            //if(spicane[i][j]<0)spicane[i][j]=1
         }
      }
   }
   cin>>idx1>>idx2;
   cout<<-1<<"\n";
   exit(0);
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cout<<spicane[i][j]<<" ";
      }
      cout<<"\n";
   }
}
