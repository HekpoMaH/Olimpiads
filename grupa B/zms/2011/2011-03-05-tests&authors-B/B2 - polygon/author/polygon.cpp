/**
PROGRAM NAME: polygon
AUTHOR: Stoyan Kapralov
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Point 
{ public: int x,y; 
};

Point A[16]; // Points
int p[16];   // Points permutation
int n;

int ok[16][16]; // ok[i][j]==true <==> A[i]-A[j] is a side of the polygon
       
int dir(Point A, Point B, Point C) 
{
    int a1=B.x-A.x, a2=B.y-A.y;
    int b1=C.x-A.x, b2=C.y-A.y;
    int p=a1*b2, q=a2*b1;
    if(p>q) return +1; // C lies in the "left" semiplane regarding AB
    if(p<q) return -1; // C lies in the "right" semi-plain regarding AB 
    return 0;          // C lies on the line AB
}

/** Check if the segment A[i]-A[j] 
    is on the convex hull 
*/
bool side_ok(int i, int j)
{ Point M = A[i], N = A[j];
  bool left=false, right=false;
  for(int k=0; k<n; k++)
    if(k!=i && k!=j)
    { int s = dir(M,N,A[k]);
      if(s==0) return false; // Three colinear points
      if(s>0) { left=true;  if(right) return false; }
      if(s<0) { right=true; if(left)  return false; }
    }
  return true;
}

bool convex() 
{
   for(int i=0; i<n; i++)
     if(!ok[p[i]][p[(i+1)%n]]) return false;
   return true;
}

double area()
{  double s = 0;
   for(int i=1; i<n; i++)
     s = s + 0.5*(A[p[i]].y + A[p[i-1]].y)*(A[p[i]].x-A[p[i-1]].x);
   s = s + 0.5*(A[p[0]].y + A[p[n-1]].y)*(A[p[0]].x-A[p[n-1]].x);
   if(s<0) s = -s;
   return s;
}

int main() 
{
    cin >> n;
    for(int i=0; i<n; i++)
      cin >> A[i].x >> A[i].y;

    
    int good=0;
    for(int i=0; i<n; i++)
      for(int j=i+1; j<n; j++)
        if(side_ok(i,j))
        {  good++;
           ok[i][j] = ok[j][i] = true;
        }
    if(good!=n) // n-gon must have exactly n sides
    { cout << 0 << endl;
      return 0;
    }

    for(int i=0; i<n; i++) 
      p[i]=i;
    
    bool conv=convex();
    while(!conv && next_permutation(p+1,p+n)) // Do not permute point A[0]
    { conv = convex(); }

    if(conv) cout << area() << endl;
    else cout << 0 << endl;

    return 0;
}

