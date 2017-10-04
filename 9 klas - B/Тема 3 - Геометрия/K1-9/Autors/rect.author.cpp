#include<cstdio>
#include<algorithm>
using namespace std;

const int n_max=1000002;
int x1[n_max],y1[n_max],x2[n_max],y2[n_max];
int n;
int x[2*n_max], y[2*n_max];

bool isVside(int xc, int ya, int yb)
{
   for(int i=1;i<=n;i++)
    {
      if(x1[i]==xc)
      if(y1[i]<=ya)
      if(y2[i]>=yb) return true;
      
      if(x2[i]==xc)
      if(y1[i]<=ya)
      if(y2[i]>=yb) return true;
    }
   return false;
}

bool isHside(int yc, int xa, int xb)
{
   for(int i=1;i<=n;i++)
    {
      if(y1[i]==yc)
      if(x1[i]<=xa)
      if(x2[i]>=xb) return true;

      if(y2[i]==yc)
      if(x1[i]<=xa)
      if(x2[i]>=xb) return true;
    }
   return false;
}

int test()
{
  int s=0;
  for(int i=1;i<=n;i++) s += 2*(x2[i]-x1[i]+y2[i]-y1[i]);
  printf("%d\n",s);
}


int main()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
  
  int k=0;
  for(int i=1;i<=n;i++)
   {k++;
    x[k]=x1[i]; y[k]=y1[i];
    k++;
    x[k]=x2[i]; y[k]=y2[i];
   }

   sort(x+1,x+k+1);
   int kx=2;
   for(int i=2;i<=k;i++)
    {x[kx]=x[i]; if(x[i]>x[kx-1]) kx++;}
   kx--;
   
   sort(y+1,y+k+1);
   int ky=2;
   for(int i=2;i<=k;i++)
    {y[ky]=y[i]; if(y[i]>y[ky-1]) ky++;}
   ky--;

  int s=0;
  
  for(int i=1;i<=kx;i++)
  for(int j=1;j<ky;j++)
   if(isVside(x[i],y[j],y[j+1])) s+= y[j+1]-y[j];

  for(int j=1;j<=ky;j++)
  for(int i=1;i<kx;i++)
   if(isHside(y[j],x[i],x[i+1])) s+= x[i+1]-x[i];
   
  printf("%d\n",s);
  //test();
}
