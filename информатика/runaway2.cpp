#include<iostream>
#include<cstdio>
using namespace std;
int tab[1000][1000];
int n,k;
int str,endc,o;
void solve(int es)
{
  int br=0;
  if(es>tab[n-1][n-1])printf("No solution");
  if(es<tab[str][endc]){endc--;br++;}
  if(es>tab[str][endc]){str++;br++;}
  printf("%d\n",br);
}
int main()
{
  cin>>n;
  endc=n-1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;i<n;j++)
    {
      scanf("%d",&tab[i][j]);
    }
  }
  cin>>k;
  for(int i=0;i<k;i++)
  {
    cin>>o;
    solve(o);
  }
  return 0;
}
