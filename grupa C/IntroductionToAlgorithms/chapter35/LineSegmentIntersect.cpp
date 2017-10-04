#include<iostream>
using namespace std;
struct point
{
  double x,y;
};
point a,b,c,d,mp1,mp2,mp3,mp4;
double showlorr(point k,point l,point m)
{
  double det=(m.x-k.x)*(l.y-k.y)-(l.x-k.x)*(m.y-k.y);
  return det;
}
int main()
{
  cin>>a.x>>a.y;
  cin>>b.x>>b.y;
  cin>>c.x>>c.y;
  cin>>d.x>>d.y;
  //Bounding box
  mp1.x=min(a.x,b.x);
  mp1.y=min(a.y,b.y);
  mp2.x=max(a.x,b.x);
  mp2.y=max(a.y,b.y);
  mp3.x=min(c.x,d.x);
  mp3.y=min(c.y,d.y);
  mp4.x=max(c.x,d.x);
  mp4.y=max(c.y,d.y);
  if(mp2.x>=mp3.x&&mp4.x>=mp1.x&&mp2.y>=mp3.y&&mp4.y>=mp1.y)
  {
    cout<<"here"<<endl;
    cout<<"No"<<endl;
    return 0;
  }
  if((showlorr(mp1,mp2,mp3)<0&&showlorr(mp1,mp4,mp3)<0)||(showlorr(mp1,mp2,mp3)>0&&showlorr(mp1,mp4,mp3)>0))
  {
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  return 0;
}
/*
2 2
5 4
4 1
3 5
*/
