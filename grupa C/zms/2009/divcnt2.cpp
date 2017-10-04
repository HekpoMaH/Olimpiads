#include<iostream>
using namespace std;
long long n,br=1,del;
long long deliteli(int x)
{
  long long td=2,brtd=0,brd=1;
  while(x!=1)
  {
    if(x%td==0)
    {
      //cout<<x<<" "<<td<<" "<<brtd<<"  4"<<endl;
      x/=td;
      brtd++;
    }
    else
    {
      //cout<<brtd<<" "<<brd<<endl;
      td++;
      brd*=(brtd+1);
      brtd=0;
    }
  }
  brd*=(brtd+1);
  return brd;
}
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>del;
    cout<<deliteli(del)<<" ";
  }
  cout<<endl;
  return 0;
}
