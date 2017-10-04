#include<iostream>
using namespace std;
int x,n,p[100];
long p1,p2;
int main()
{
  cin>>n;
  cin>>x;
  for(int i=0;i<=n;i++)cin>>p[i];
  p1=p[0];
  for(int i=1;i<=n;i++)p1=p1*x+p[i];
  p2=p[0];
  for(int i=1;i<=n;i++)p2=p2*(x+1)+p[i];
  cout<<p2-p1<<endl;
  return 0;
}
