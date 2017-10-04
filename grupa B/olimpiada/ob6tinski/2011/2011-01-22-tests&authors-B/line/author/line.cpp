/**
PROGRAM NAME: line
AUTHOR: Stoyan Kapralov
*/
#include <iostream>
#include <algorithm>
using namespace std;

class Point 
{
public:
    int x,y;
};

Point A[10];
int n;

int dist(Point A, Point B)
{ int x=B.x-A.x;
  int y=B.y-A.y;
  return abs(x)+abs(y);
}

int main() 
{ cin >> n;
  for(int i=0; i<n; i++)
    cin >> A[i].x >> A[i].y;

  int p[10];
  for(int i=0; i<n; i++)
    p[i]=i;
   
  int d = 1000;  
  
  do
  { int s=0;
    for(int i=1; i<n; i++)
      s = s + dist(A[p[i-1]],A[p[i]]);
    if(d>s) d = s;
  } while(next_permutation(p,p+n));
  
  cout << d << endl; 

  return 0;
}
