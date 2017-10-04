#include<iostream>
#include<iomanip>
#include <algorithm>
using namespace std;

const int N=1000;
int n;
struct ps {double a, b;};
ps p[N];


bool cmp(ps p1, ps p2)
{
 return p1.a/p1.b > p2.a/p2.b;
}

int main()
{
 cin >> n;
 for(int i=0;i<n;i++) cin >> p[i].a >> p[i].b;

 sort(p,p+n,cmp);

 double sa,sb;
 double t=0;

 sa=0.0;
 sb=(double)n-0.000001;

 int ia, ib;

 double dt=0.001;

 while(sa<sb)
 {

   ia=(int)sa;
   ib=(int)sb;
   sa += dt/p[ia].a;
   sb -= dt/p[ib].b;
   t += dt;

 }
 cout << setprecision(10) << t << endl;

}

