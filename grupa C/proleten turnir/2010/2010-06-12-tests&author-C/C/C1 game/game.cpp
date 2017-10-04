#include <cstdio>
#include <algorithm>
using namespace std;


const int MAXM = (1<<20);

int n;
int a[MAXM];

int main()
{ scanf("%d",&n);

  int m = 1;
  for(int i=1; i<=n; i++)
    m = m * 4;
    
  for(int i=0; i<m; i++)
    scanf("%d",&a[i]);
    
  while(m>1)
  { int k, p;
    for(k=0, p=0; p<m; p = p+2)
    { a[k] = min(a[p],a[p+1]);
      k++;
    }  
    m = k;    
    for(k=0, p=0; p<m; p = p+2)
    { a[k] = max(a[p],a[p+1]);
      k++;
    }  
    m = k;
  }
  
  printf("%d\n",a[0]);
  
  return 0;
}
    
