#include <stdio.h>
#define MAXN 500001

// heap element
typedef struct
{ double k; int ch,zn; //time when a catch b
  int a,b; } heapel;

typedef struct // description of a runner r
{ double s; // spead of runner
  int s1,s2;
  int d,    // distance from Start-Final
      p;    // pursued runner
} runerel;

int N,L;
heapel h[MAXN];int hsz; // heap
runerel r[MAXN];        // list of runners

int gcd(int a,int b)
{  int r;
   if(a<b) {r=a;a=b;b=r;}
   while((r=a%b)!=0) {a=b;b=r;}
   return b;
}
void swap(int i, int j)
{  int t; double dt;
//   dt=h[i].k; h[i].k=h[j].k;h[j].k=dt;
     t=h[i].ch; h[i].ch=h[j].ch;h[j].ch=t;
     t=h[i].zn; h[i].zn=h[j].zn;h[j].zn=t;
     t=h[i].a; h[i].a=h[j].a;h[j].a=t;
     t=h[i].b; h[i].b=h[j].b;h[j].b=t;
}

void heapify(int i)
{  int j = i;
//   if(2*i<=hsz && h[j].k>h[2*i].k) j=2*i;
   if(2*i<=hsz && h[j].ch*h[2*i].zn>h[j].zn*h[2*i].ch) j=2*i;
//   if(2*i+1<=hsz && h[j].k>h[2*i+1].k) j=2*i+1;
   if(2*i+1<=hsz && h[j].ch*h[2*i+1].zn>h[j].zn*h[2*i+1].ch) j=2*i+1;
   if(j!=i) { swap(i,j); heapify(j); }
}

void make_heap()
{  int i;
   for(i=hsz/2;i>=1;i--) heapify(i);
}

void eliminate()
{  int a,b,x,y,z,w;int i;
   a=h[1].a;b=h[1].b;
   if(r[a].p!=0)
   {  //b will be eliminated
//      h[1].k=(double)h[1].ch/(double)h[1].zn;
//      printf("%d %lf\n",b,h[1].k);
//      printf("%d %d %d\n",b,h[1].ch,h[1].zn);
      printf("%d\n",b);
      r[a].p=r[b].p;r[b].p=0;
      if(a!=r[a].p && r[a].s1>r[r[a].p].s1)
      {  b=h[1].b=r[a].p; w=r[b].d;
         if(a>b) w+=L;
         //h[1].k=(x-r[a].d)/(r[a].s-r[b].s);
         x=100*(w-r[a].d);
         y=r[a].s1-r[b].s1;
         z=gcd(x,y);
         h[1].ch=x/z;
         h[1].zn=y/z;
      }
      else { //h[1].k=h[hsz].k;
             h[1].ch=h[hsz].ch;h[1].zn=h[hsz].zn;
             h[1].a=h[hsz].a;h[1].b=h[hsz--].b;
             }
   }
   else
   {   //h[1].k=h[hsz].k;
       h[1].ch=h[hsz].ch;h[1].zn=h[hsz].zn;
       h[1].a=h[hsz].a;h[1].b=h[hsz--].b; }
   heapify(1);
}

int main()
{  int i,x,y,z;
   //input
   scanf("%d %d", &N,&L);
   for(i=1;i<=N;i++)
   {  scanf("%d %d.%d",&r[i].d,&r[i].s1,&r[i].s2);
//      printf("%d %d %d\n",r[i].d,r[i].s1,r[i].s2);
      r[i].s1=100*r[i].s1+r[i].s2;
      r[i].p=i+1;
   }
   r[N].p=1;r[N+1].d=L+r[1].d;r[N+1].s1=r[1].s1;

   //initialization of heap
   hsz=0;
   for(i=1;i<=N;i++)
   {  if(r[i].s1>r[i+1].s1)
      {
         //h[++hsz].k=(r[i+1].d-r[i].d)/(r[i].s-r[i+1].s);
         x=100*(r[i+1].d-r[i].d);
         y=r[i].s1-r[i+1].s1;
         z=gcd(x,y);
         h[++hsz].ch=x/z;
         h[hsz].zn=y/z;
         h[hsz].a=i; h[hsz].b=i+1;
         if(i==N) h[hsz].b=1;
      }
   }

   make_heap();
//for(i=1;i<=hsz;i++) printf("%d %d %d %d\n", h[i].a,h[i].b,h[i].ch,h[i].zn);

   //elimination
   while(hsz>=1) {eliminate();
//for(i=1;i<=hsz;i++) printf("%d %d %d %d\n", h[i].a,h[i].b,h[i].ch,h[i].zn);
}
   printf("Winner(s):");
   for(i=1;i<=N;i++) if(r[i].p!=0) printf(" %d",i);
   printf("\n");
}

