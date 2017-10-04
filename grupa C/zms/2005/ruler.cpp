#include<iostream>
using namespace std;
int n,m;
void write(int n,int x)
{
  for(int i=1;i<=n;i++)cout<<"-";
  if(x>=0)cout<<" "<<x;
  cout<<endl;
}
void recurse(int k)
{
  //cout<<k<<endl;system("pause");
  if(k>1)recurse(k-1);
  write(k,-1);
  if(k>1)recurse(k-1);
}
int main()
{
  cin>>n>>m;
  write(m,0);
  for(int i=1;i<=n;i++)
  {
    recurse(m-1);
    write(m,i);
  }
  return 0;
}
