#include <cstdio>

const int max=500000;
int a[max+1];
int n;

int main()
{
  scanf("%d",&n);
  for(int i=1;i<=n; i++)
  {
    int j1,j2;
    scanf("%d%d",&j1,&j2);        
    for(int j=j1;j<=j2;j++) 
     if(a[j]==0) a[j]=1;
     else a[j]=0;      
  }
  
  int m=0;
  int c=0;
  int j=1;
  while(j<max)
  { while(a[j]==0) j++;
    c=0;
    while(a[j]==1) {j++; c++;}
    if(m<c)m=c;
  }
  
  printf("%d\n",m);
   
}
