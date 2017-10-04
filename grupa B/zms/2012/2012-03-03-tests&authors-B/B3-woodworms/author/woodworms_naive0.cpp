#include<iostream>
#include<iomanip>
using namespace std;

const int N=1000;
int n;
struct ps {double a, b;};
ps v[N];
int p[N];
double rec=0.0;


double time()
{
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
   sa += dt/v[p[ia]].a;
   sb -= dt/v[p[ib]].b;
   t += dt;
   
 }      
 return t; 
}

bool ne(int i, int j)
{
 for(int k=0;k<i;k++) if(p[k]==j) return false;    
 return true;
}

void gen(int i)
{
  if(i==n) 
  {
//    for(int j=0;j<n;j++) cout << p[j];
//    cout << endl;
    double t;
    t=time();
//    cout << setprecision(10) << t << endl; 
    if(t>rec) rec=t; 
    return;
  }   
     
  for(int j=0;j<n;j++)
  if(ne(i,j))
   { p[i]=j;
     gen(i+1);
     p[i]=-1;
   }
}

int main()
{
 cin >> n;
 for(int i=0;i<n;i++) cin >> v[i].a >> v[i].b;
 for(int i=0;i<n;i++) p[i]=-1;
  
 gen(0); 
 
// cout << "rec=";
 cout << setprecision(10) << rec << endl;  
 
}

