#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAX2N = 600002;

int x[MAX2N], y[MAX2N];

int compare(const void *p, const void *q)
{ return *(int *)p - *(int *)q;
}

int main()
{  int x0, x1, y0, y1;
   int N;
   scanf("%d", &N);
   for(int i=0; i<N; i++)
     {  scanf("%d %d %d %d",&x0, &y0, &x1, &y1);
        if (x0 < x1)
          { x[2*i] = 2*x0; x[2*i+1] = 2*x1 + 1;
          }
        else
          { x[2*i] = 2*x1; x[2*i+1] = 2*x0 +1;
          }
        if (y0 < y1)
          { y[2*i] = 2*y0; y[2*i+1] = 2*y1 + 1;
          }
        else
          { y[2*i] = 2*y1; y[2*i+1] = 2*y0 +1;
          }  
     }
   qsort(x, 2*N, sizeof(int *), compare);
   qsort(y, 2*N, sizeof(int *), compare);
   int sx = 0, sy = 0;
   int maxi = 0;
   for(int i=0; i < 2*N; i++)
     {  if (x[i]%2)
          sx--;
        else
          { sx++; 
            if (maxi < sx) maxi = sx;
          }
        if (y[i]%2)
          sy--;
        else
          { sy++; 
            if (maxi < sy) maxi = sy;
          }
     }  
   printf("%d\n",maxi);                   
   return 0;   
}
