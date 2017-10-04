#include <iostream>
using namespace std;

int sieve[32000]={0};
int prime[4000];
int pcnt;

void genprimes(int m)
{ pcnt = 0;
  for(int d=2; d<m; d++)
  if(sieve[d]==0)
  { pcnt++; prime[pcnt]=d;
    for(int j=2*d; j<=m; j=j+d)
      sieve[j] = 1;
  }    
}

int divcnt(int x)
{ int dcnt=1;
  
  for(int i=1; prime[i]*prime[i]<=x; i++)
  { int k=0;
    while(x%prime[i] == 0)
    { x = x/prime[i]; 
      k++;  
    }
    dcnt = dcnt * (k+1);
  }
    
  if(x>1) dcnt = dcnt*2;

  return dcnt;    
}

int main()
{ genprimes(32000);
  
  int n,x;
  cin >> n;
  
  for(int k = 1; k<n; k++)
  { cin >> x;
    cout << divcnt(x) << " ";      
  }
  cin >> x;
  cout << divcnt(x) << endl;
  
  return 0;
}         
