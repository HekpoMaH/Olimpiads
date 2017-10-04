#include<cstdio>
#include<cstdlib>

const int n_max=1000; // how many triangles

struct point {int x,y;};

char t[n_max*41000]; // for each possible value of an area

point a[n_max],b[n_max],c[n_max];
int v[n_max];

int n,m; // nunber of triangles and number of considered trianagles

int s(point a, point b, point c)
{ point t; 
  int v;
   if((a.y==b.y)||(a.y==c.y)||(b.y==c.y))
   {
   if (a.y==c.y) {t=b;b=c;c=t;}
   if (b.y==c.y) {t=a;a=c;c=t;}
   v = abs(a.x-b.x)*abs(c.y-b.y);
   }
   else if((a.x==b.x)||(a.x==c.x)||(b.x==c.x))
   {
    if (a.x==c.x) {t=b;b=c;c=t;}
    if (b.x==c.x) {t=a;a=c;c=t;}
    v = abs(a.y-b.y)*abs(c.x-b.x);
   }
   else return 0;
   if(v==0) return 0;
   if (v%2==0) return v/2;
   return 0;
}

int main()
{
  int n;
  t[0]=1;
  scanf("%d",&n);
  for (int i=0;i<n;i++)
   {
     scanf("%d%d",&a[i].x,&a[i].y);
     scanf("%d%d",&b[i].x,&b[i].y);
     scanf("%d%d",&c[i].x,&c[i].y);
   }

   int nt=0;
   for (int i=0;i<n;i++)
   { 
     int w=s(a[i],b[i],c[i]);
//     printf("w=%d\n",w);
     if(w>0) {nt++; v[nt]=w;}
   }
   
   int ss=0;   
   for(int i=1;i<=nt;i++) ss += v[i];
   
//   printf("nt=%d\n",nt);
//   for(int i=1;i<=nt;i++) printf("%d ",v[i]);
//   printf("\nss=%d\n",ss);

   for(int i=1;i<=nt;i++)
   {
     for(int j=ss;j>=0;j--)
      if(t[j]==1) t[j+v[i]]=1;
//     for(int k=0;k<=ss;k++) printf("%d ",t[k]);
//     printf("\n"); 
   }

   for(int i=ss/2;i>1;i--)
    if(t[i]==1){printf("%d %d\n",i,ss-i); break;}
}
