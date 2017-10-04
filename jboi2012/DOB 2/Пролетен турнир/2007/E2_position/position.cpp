#include <iostream>
using namespace std;
struct h
{ int a;
  int ch;
  int min;
  string s;
};
bool f(h x1, h x2)
{ if (x1.a<x2.a) return 1;
  return 0;
} 
int main()
{h m[1001];
  int n;
  cin>>n;
 for(int i=0;i<n;i++)
 { 
 cin>>m[i].ch>>m[i].min>>m[i].s;
 m[i].a = m[i].ch*60 + m[i].min;
 }
 sort(m,m+n,f);
 for(int i=0;i<n;i++)
{
 cout<<m[i].s<<endl;
}
return 0;
}
