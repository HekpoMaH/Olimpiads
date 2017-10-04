#include<iostream>
using namespace std;
int a[104],x,s,m;
int main()
{
  cin>>m>>x;
  for(int i=0;i<=m;i++)cin>>a[i];
  s=a[0];
  for(int i=1;i<=m;i++){s=s*x+a[i];}
  cout<<s<<endl;
  return 0;
}
