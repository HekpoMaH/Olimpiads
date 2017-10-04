#include <iostream>
using namespace std;

int n;
int a[20],b[20];
int p[20];

int nod(int a, int b)
{ int r = a%b;
  while (r>0)
  { a = b;
    b = r;
    r = a%b;
  }
  return b;
}

bool grater(int i, int j)
{ return a[i]*b[j]>a[j]*b[i]; }

int main()
{ cin >> n;
  for(int i=0; i<n; i++)
    cin >> a[i] >> b[i];
    
  for(int i=0; i<n; i++)
  { int d = nod(a[i],b[i]);
    a[i] = a[i] / d;
    b[i] = b[i] / d;
  }
  
  for(int i=0; i<n; i++)
    p[i] = i; 
  for(int i=1; i<n; i++)
  { int j=i-1;
    while(j>=0 && grater(p[j],p[j+1]))
    { int w=p[j]; p[j]=p[j+1]; p[j+1]=w;
      j--;
    }
  }
  
  cout << n << endl;
  for(int i=0; i<n; i++)
    cout << a[p[i]] << " " << b[p[i]] << endl;
   
  return 0;
}
            
