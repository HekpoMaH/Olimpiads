#include<iostream>
using namespace std;
struct str
{
  long long hh,p;
};
long long m,n,v,a[490005],br,s,pp,h;
double z;
str st[490005];
int main()
{
  cin>>n>>m>>v;
  for(int i=0;i<m*n;i++)cin>>a[i];
  sort(a,a+n*m);
  for(int i=0;i<m*n;i++)
  {
    br++;
    if(a[i]!=a[i+1])
    {
      st[s].hh=a[i];
      st[s].p=br;
      //cout<<a[i]<<" "<<br<<endl;
      s++;
      br=0;
    }
  }
  /*for(int i=0;i<s;i++)
  {
    cout<<st[i].hh<<" "<<st[i].p<<endl;
  }*/

  z=st[0].hh;
  pp=st[0].p;
  for(int i=0;i<s;i++)st[i].hh-=(long long)z;
  for(int i=0;i<s;i++)
  {
    cout<<st[i].hh<<" "<<st[i].p<<endl;
  }
  long long y,t;
  for(int i=0;i<s;i++)
  {
    h=st[i+1].hh*pp;
    cout<<h<<endl;cout<<h<<" "<<z<<" "<<v<<" "<<pp<<endl;
    if(h<=v)
    {
      v-=h;
      z+=(long long)st[i+1].hh;
      pp+=st[i].p;
      for(int j=i;j<s;j++){cout<<st[j].hh<<"  ";y=st[j].hh;t=st[i].hh;st[j].hh=y-t;cout<<st[j].hh<<endl;}
      for(int d=0;d<s;d++)
      {
        cout<<st[d].hh<<" "<<st[d].p<<endl;
      }
    }
    else if(h>v)
    {
      z+=(double)v/pp;
      break;
    }
    else if(s-1==i&&v>0)
    {
      z+=(double)v/pp;
    }

  }
  cout<<z<<" "<<pp<<endl;
  return 0;
}
