#include<iostream>
using namespace std;

int a,b,c,d,r;

int main()
{
  cin >> a >> b >> c >> d;
  if(b<a) swap(a,b);
  if(d<c) swap(c,d);
  if(d<b) {swap(a,c); swap(b,d);}

   if(c>b) r=-1;
   else if(c<a) r=b-a;
   else r=b-c;

  cout << r << endl;
}
