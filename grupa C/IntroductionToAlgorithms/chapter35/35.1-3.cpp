#include<iostream>
using namespace std;
struct point
{
  double x,y;
  char name;
};
point p[26];
int n;
bool strline(point k,point l,point m)
{
  double det=(m.x-k.x)*(l.y-k.y)-(l.x-k.x)*(m.y-k.y);
  if(det==0)return true;
  return false;
}
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>p[i].name>>p[i].x>>p[i].y;
  }
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      for(int k=j+1;k<n;k++)
      {
        if(strline(p[i],p[j],p[k])==true)
        {
          cout<<p[i].name<<" "<<p[j].name<<" "<<p[k].name<<endl;
        }
      }
    }
  }
  return 0;
}
/*
vhod
6
a 3 3
b 7 3
c 10 3
d 4 4
e 8 8
f 11 11
izhod
a b c
a d e
a d f
a e f
d e f
*/
