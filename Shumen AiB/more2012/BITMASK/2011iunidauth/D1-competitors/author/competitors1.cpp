//Task: competitors
//Author: Biserka Yovcheva
#include <iostream>
#include<cstdlib>
using namespace std;
int sets[16][32],n,m, ns;
int workSet[32];
int maxTeam,mb=0;
void read()
{
  int i,j,p, l;
  cin>>n>>m;
  for(i=1;i<=n;i++)
  {
    cin>>p;
  for(j=1;j<=p;j++)
  {
    cin>>l;
    sets[i][l]=1;
  }
  }
  mb=n+1;
}

void initSet()
{
  int i;
  for(i=0;i<32;i++)workSet[i]=0;
}
void unionSet(int k)
{
  int i;
  for(i=0;i<32;i++)
  {
    if(!workSet[i]&&sets[k][i])
    {
      workSet[i]=1;ns++;
    }
  }
}
int checkWorkSet(int t)
{
  int i;
  initSet();
  ns=0;
  for(i=1;i<=n;i++)
  {
    if(t&(1<<i))unionSet(i);
  }
  return ns;
}
void checkMax(int t)
{
  int i,br=0;
  for(i=1;i<=n;i++)
  if(t&(1<<i))br++;
  if(br<mb)
  {
    mb=br;
    maxTeam=t;
  }
}

void print()
{
  int i, br=0,k;
  for(i=n; i>=1;i--)
  if(maxTeam&(1<<i)){br++;k=i;}
  cout<<br<<endl;
  cout<<k;
  for(i=k+1;i<=n;i++)
  if(maxTeam&(1<<i))cout<<' '<<i;
  cout<<endl;
}

int main()
{
  int i;
  read();
  for(i=1;i<=(1<<n+1);i++)
  {
   if(checkWorkSet(i)==m)
    {

      checkMax(i);

    }
  }
  print();
  return 0;
}
