//Task: competitors
//Author: Biserka Yovcheva
#include <iostream>
#include<cstdlib>
using namespace std;
int sets[16][32],n,m, ns;
int workSet[32];
int team[16],maxTeam[16],mb=0;
void printTeam();
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
int checkWorkSet()
{
  int i;
  initSet();
  ns=0;
  for(i=1;i<=n;i++)
  {

  if(team[i])unionSet(i);
  }
  return ns;
}
void checkMax()
{
  int i,br=0;
  //printTeam();
  for(i=1;i<=n;i++)
  if(team[i])br++;
  if(br<=mb)
  {
    mb=br;
    for(i=1;i<=n;i++)maxTeam[i]=team[i];
  }
}

void print()
{
  int i, br=0,k;
  for(i=n; i>=1;i--)
  if(maxTeam[i]){br++;k=i;}
  cout<<br<<endl;
  cout<<k;
  for(i=k+1;i<=n;i++)
  if(maxTeam[i])cout<<' '<<i;
  cout<<endl;
}

void perm(int i)
{
  int j;
  for(j=0;j<=1;j++)
  {
    team[i]=j;
    if(i==n)
    {
    if(checkWorkSet()==m)
    {

      checkMax();

    }
    }
    else perm(i+1);
  }
}

int main()
{
  read();
  perm(1);
  print();
  return 0;
}
