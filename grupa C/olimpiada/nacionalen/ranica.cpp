#include<iostream>
using namespace std;
int teglo[100],cena[100],n,r,mem[100];
int prog(int ost,int next)
{
  if(mem[ost]!=-1)return mem[ost];
  int mx=0;
  int sp;
  for(int i=next;i<n;i++)
  {
    if(ost-teglo[i]>=0)
    {
      sp=prog(ost-teglo[i],i+1)+cena[i];
      if(sp>mx)mx=sp;
    }
  }
  mem[ost]=mx;
  return mem[ost];
}
int main()
{
  cin>>n>>r;
  for(int i=0;i<n;i++)cin>>teglo[i]>>cena[i];
  for(int i=0;i<100;i++)mem[i]=-1;
  cout<<prog(r,0)<<endl;
  return 0;
}
