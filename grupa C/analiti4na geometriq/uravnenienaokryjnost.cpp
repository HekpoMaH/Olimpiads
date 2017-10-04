#include<iostream>
using namespace std;
int x,y,r,x1,y1;
void okr(int x,int y)
{
  if((x-x1)*(x-x1)+(y-y1)*(y-y1)==r*r){cout<<"prinadleji"<<endl;return;}
  if((x-x1)*(x-x1)+(y-y1)*(y-y1)>r*r){cout<<"izvyn"<<endl;return;}
  if((x-x1)*(x-x1)+(y-y1)*(y-y1)<r*r){cout<<"vytre"<<endl;return;}
}
int main()
{
  cin>>x1>>y1>>r;
  cin>>x>>y;
  okr(x,y);
  return 0;
}
