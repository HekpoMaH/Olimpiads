#include<iostream>
using namespace std;

struct f{int a,b;}d[10000000];

bool cmp(f x, f y)
{ return x.a*y.b < x.b*y.a;}

int nod(int a, int b)
{
  while(a!=b)
  if(a>b) a=a-b;
  else b=b-a;
  return a;
}

int main()
{
 int z,m,n;
 cin >> z >> m >> n;
 int c=0;
 for(int b=2;b<=z;b++)
  for(int a=1;a<b;a++)
   if(nod(a,b)==1){d[c].a=a;d[c].b=b;c++; }
 
 sort(d,d+c,cmp);
/* for(int i=0;i<c;i++)
 cout<<d[i].a<<"/"<<d[i].b<<endl;*/
 
 for(int i=0;i<c;i++)
  if((d[i].a==m)&&(d[i].b==n))
    {
      cout << d[i+1].a << " " << d[i+1].b << endl;
    }
}
 
 
