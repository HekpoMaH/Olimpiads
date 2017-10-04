#include<iostream>
using namespace std;
void check(int k)
{
  int a;
  cin>>a;
  int b=0;
  int i=2;
  int c;
  while(i<=k)
  {
    cin>>c;
    if(c>a)a=c;
    else if(c>b)b=c;
    else
    {
      i++;
      while(i<=k){cin>>c;i++;}
      cout<<0;return;
    }
    i++;
  }
  cout<<1;
}
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {int k;cin>>k;check(k);}
  cout<<endl;
  return 0;
}

