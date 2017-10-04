#include <iostream>
using namespace std;

int n,k;
int dist[1024]; 

int next(int p, int d) // returns max q, p<=q<=n, such that dist(p,q)<=d 
{ while(p<n && dist[p]<=d)
  { d = d - dist[p];
    p++;
  }
  return p;
}

int cnt(int d)
{ int p = 1;
  int k = 0;
  while(p <= n)
  { p = next(p,d);
    p = next(p,d)+1;
    k++; 
  }    
  return k;  
}

int main()
{  int a = -1, b = 0;
   cin >> n >> k;  
   for(int i=1; i<n; i++)
   { cin >> dist[i];
     b = b + dist[i];
   }       
   
   while(a+1 < b) // binary search d=a - impossible; d=b - possible
   { int d = (a+b)/2;
     if(cnt(d)>k) a = d; else b = d;
   }  
   cout << b << endl;
   
   return 0;
}
                      
