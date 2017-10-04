#include<iostream>
using namespace std;
struct point
{
  double x,y;
};
point p[26];
int n,pos;
int showlorr(point k,point l,point m)
{
  double det=(m.x-k.x)*(l.y-k.y)-(l.x-k.x)*(m.y-k.y);
  if(det>0)return 1;
  if(det<0)return -1;
}
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>p[i].x>>p[i].y;
  }
  p[n].x=p[0].x;p[n].y=p[0].y;
  p[n+1].x=p[1].x;p[n+1].y=p[1].y;
  pos=showlorr(p[0],p[1],p[2]);
  for(int i=0;i<n;i++)
  {
    if(showlorr(p[i],p[i+1],p[i+2])!=pos)
    {
      cout<<"no."<<endl;return 0;
    }
  }
  cout<<"yes"<<endl;
  return 0;
}
/*
vhod
5
1 1
2 0.5
4 5
3 7
1.5 6
izhod
yes
*/
/*
vhod
5
1 1
2 0.5
1.8 3
3 7
1.5 6
izhod
no.
*/