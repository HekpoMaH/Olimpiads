#include<iostream>
#include<deque>
#include<string>
#include<vector>
#define MAX 99999999
using namespace std;
  char e[40];
  char xpo[1000];
  int xpd[1000];


int eval()
{
  int s=0;
  s=xpd[0];
  for(int i=0;i<strlen(e)/2;++i)
  {
    if(xpo[i]=='+')
      s+=xpd[i+1];
    else
      s-=xpd[i+1];
  }
  return s;
}

void show()
{
  cout<<eval()<<"\n";
}

int pmin(int x)
{
  int s[20];
  int z=0;
  int v=0;
  int i=0;
 for( i=x-1;i>-1;--i)
  {
    if(xpo[i]=='*')
  {
    break;
  }
  else{
    if(z==0)v=0;else v=s[z-1];
   if(xpo[i]=='+')
      s[z]=v+xpd[i];
   else
      s[z]=v-xpd[i];
  }

  }
  if(i==-1)i=0;
  int w=MAX;
  for(int g=0;g<z;++g)
  {
    if(s[g]<w)w=s[g];
  }
  return w;
}

int main()
{
  int f=0;
  vector<int> j;
  cin>>e;


  for(int nu=0;nu<strlen(e);++nu)
  {
      xpo[nu]=e[2*nu+1];
      xpd[nu]=(int)e[2*nu];
  }
  int v=0;
  int q=0;
  for(int p=0;p<strlen(e)/2;++p)
  {
    if(xpo[p]=='*'){q=pmin(p);
    v++;
    if(q<xpd[p]) {
        j.push_back(q);

       }
       else{
        0;
       }
        cout<<eval();
    }
  }
  if(v==0)
  show();
  return 0;
}