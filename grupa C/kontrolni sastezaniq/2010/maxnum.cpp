#include<iostream>
using namespace std;
int a[100];
bool cmp(int x, int y)
{
  long long xy,yx,x1,y1;
  x1=x;y1=y;
  while(y1>0){x1*=10;y1/=10;}
  xy=x1+y;
  x1=x;y1=y;
  while(x1>0){y1*=10;x1/=10;}
  yx=y1+x;
  if(xy>yx)return true;
  if(xy==yx&&x>y)return true;
  return false;
}
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n,cmp);
  for(int i=0;i<n;i++)cout<<a[i];
  cout<<endl;
  return 0;
}
