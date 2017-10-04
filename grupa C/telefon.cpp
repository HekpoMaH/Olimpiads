#include<iostream>
using namespace std;
int timee[11]={11,2,3,4,5,6,7,8,9,10},nomer[10];
int n,br;
void solve(int pos,int sbor,int cifri)
{
  if(pos==cifri&&sbor==n)
  {
    br++;
    return;
  }
  for(int i=0;i<=9;i++)
  {
    if(sbor+timee[i]<=n&&pos+1<=cifri)
    {
      nomer[pos+1]=i;
      solve(pos+1,sbor+timee[i],cifri);
      nomer[pos+1]=0;
    }
  }
}
int main()
{
  cin>>n;
  for(int i=1;i<=8;i++)
  {
    if(i==1)
    {
      nomer[1]=1;
      solve(1,timee[i],3);
      nomer[1]=0;
    }
    else
    {
      nomer[1]=i;
      solve(1,timee[i],5);
      nomer[1]=0;
    }
  }
  cout<<br<<endl;
  return 0;
}
