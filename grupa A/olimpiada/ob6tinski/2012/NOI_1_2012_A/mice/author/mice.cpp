#include<iostream>
using namespace std;

long long int k;
struct {long long int x, y, a;} d[10001];
int p=-1;
int ms=0;

bool empty(long long int x, long long int y)
{
  for(int i=0;i<p;i++)
   if((d[i].x==x)&&(d[i].y==y)) return false;
  return true;
}

int sum(long long int x, long long int y)
{
  if(!empty(x,y)) return 0;
  int s=0;
  for(int i=0;i<p;i++)
   {
     if(((d[i].x==x)&&(d[i].y==y+1))||
        ((d[i].x==x)&&(d[i].y==y-1))||
        ((d[i].y==y)&&(d[i].x==x+1))||
        ((d[i].y==y)&&(d[i].x==x-1)))
          s += d[i].a;
  }
  return s;
}

int main()
{
  cin >> k;
  for(int i=1;i<=k;i++)
   {
     long long int x, y, a;
     cin >> x >> y >> a;
     bool f=false;
     for(int j=0;j<=p;j++)
      if((d[j].x==x)&&(d[j].y==y))
       {f=true;
        d[j].a += a;
        break;
       }

     if(f) continue;
     p++;
     d[p].x=x;
     d[p].y=y;
     d[p].a = a;
   }
  p++;

   for(int j=0;j<p;j++)
   { long long int x=d[j].x;
     long long int y=d[j].y;
     if(y+1<1000001) ms=max(ms,sum(x, y+1));
     if(y-1>0)ms=max(ms,sum(x, y-1));
     if(x+1<1000001)ms=max(ms,sum(x+1,y));
     if(x-1>0) ms=max(ms,sum(x-1,y));
   }
   cout << ms << endl;
}
