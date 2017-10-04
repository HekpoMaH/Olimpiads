// you can make functions inline for speed up
// this makes them like defines 
//        example:  inline vec len2() { x*x + y*y }
// is the same as:  #define len2(a) ( a.x*a.x + a.y*a.y)

#include<bits/stdc++.h>
using namespace std;

// can be int, double, ...
typedef double type;

const double eps=1e-9;
const double pi = acos(-1.0);

// used for both points and vectors
// a point has the same coordinates as a vector starting at (0,0)
// use capital letters for point vars
// use small letters or pairs of capital letters for vector vars
struct vec {
  type x, y;

  // constructors
  vec() {}
  vec(type _x, type _y) { x = _x; y = _y; }

  vec operator+(vec b) { return vec(x+b.x, y+b.y); }
  vec operator-(vec b) { return vec(x-b.x, y-b.y); }

  // k is a proportion; AB*(-1) is the opposite vector BA
  // note that you can write (-1)*AB because there is no (-1).operator*(AB)
  vec operator*(type k) { return vec(k*x, k*y); }
  
  // use len^2 when just comparing lens
  type len2() { return x*x + y*y; }
  vec rot(double alpha)
  {
	return vec(x*cos(alpha)-y*sin(alpha),x*sin(alpha)+y*cos(alpha));
  }

  // by Pitagoras
  // u.len() is denoted by |u|
  double len() { return sqrt( this->len2() ); }
};

// dot(u,v) = u.x*v.x + u.y*v.y     <-- to rememeber
// dot(u,v) = |u|*|v|*cos(alpha)
//          = +/- |u|*|v_perp|
// dot(u,u) = |u|^2
// dot(u,v) = dot(v,u)
// dot(u,v) = 0 <=> u _|_ v
type dot(vec u, vec v) {
  return u.x*v.x + u.y*v.y;
}

// cross(u,v) = u.x*v.y - v.x*u.y   <-- to remember
// cross(u,v) = |u|*|v|*sin(alpha)
//            = |u|*h
//            = +/- S_parallelogram
// orient( cross(AB,BC) ) > 0 => (A,B,C) are counter-clockwise
type cross(vec u, vec v) {
  return u.x*v.y - v.x*u.y;
}
type r;
vec A,B;
int main(){
   cin>>r>>A.x>>A.y>>B.x>>B.y;
   vec AB=B-A;
   r*=2;
   //cout<<AB.len()<<"\n";
   int br=(int)(AB.len()/r);
   if(AB.len()>br*r)br++;
   cout<<br<<"\n";
}
