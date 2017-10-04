#include<cstdio>

const int max=5000000;
bool e[max+2];
int n,a,b;

void make()
{
  e[0]=e[1]=1;
  int k=2;
  while(k<max-1)
  { 
   while(e[k]==1) k++;
   int i=k+k;
   while(i<=max) { e[i]=1; i +=k;}
   k++;
  }
}


int main()
{
  make();

  scanf("%d",&n);
  int mc=0;
  int v;
  for(int j=1;j<=n;j++)
  {
    scanf("%d",&v);
    int i=2;
    int c=0;
    while(i<=v/2)
    {
     if(e[i]==0)if(e[v-i]==0) c++; 
	 i++;
   }
   if(mc<c) mc=c;
  }
  printf("%d\n",mc);
}


