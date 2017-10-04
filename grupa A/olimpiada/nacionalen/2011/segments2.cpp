#include<bits/stdc++.h>
using namespace std;
const int nmax=209;
typedef double type;
const double pi = acos(-1.0);
struct vec {
  type x, y;

  vec() {}
  vec(type _x, type _y) { x = _x; y = _y; }

  vec operator+(vec b) { return vec(x+b.x, y+b.y); }
  vec operator-(vec b) { return vec(x-b.x, y-b.y); }

  vec operator*(type k) { return vec(k*x, k*y); }
  
  type len2() { return x*x + y*y; }
  vec rot(double alpha){
     return vec(x*cos(alpha)-y*sin(alpha),x*sin(alpha)+y*cos(alpha));
  }

  double len() { return sqrt( this->len2() ); }
};

type dot(vec u, vec v) {
  return u.x*v.x + u.y*v.y;
}
type cross(vec u, vec v) {
  return u.x*v.y - v.x*u.y;
}
vec P[nmax];
int n;
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
   }
}
