#include<iostream>
#include<algorithm>
using namespace std;
struct point
{
  int x,y;
};
bool cmp(point a,point b)
{
  if(a.x>b.x)return true;
  if(a.x<b.x)return false;
  if(a.y>b.y)return true;
  return false;
}
point p[100],cd;
int nx,com,n2;
int main()
{
  cin>>nx;
  for(int i=0;i<nx;i++)cin>>p[i].x>>p[i].y;
  //cout<<"-------------"<<endl;
  make_heap(p,p+nx,cmp);
  while(cin>>com)
  {
    if(com==1)
    {
      cin>>cd.x>>cd.y;
      p[nx].x=cd.x;p[nx].y=cd.y;
      push_heap(p,p+nx+1,cmp);
      nx++;
    }
    if(com==2)
    {
      n2=nx;
      cout<<p[0].x<<" "<<p[0].y<<endl;
      pop_heap(p,p+nx,cmp);
      nx--;
      //make_heap(p,p+nx,cmp);
    }
  }
  //for(int i=0;i<nx;i++)cout<<p[i].x<<" "<<p[i].y<<endl;
  return 0;
}
