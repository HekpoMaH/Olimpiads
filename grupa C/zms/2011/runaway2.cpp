#include<iostream>
#include<cstdio>
using namespace std;
int tab[1005][1005];
int n,k;
int str,endc,o;
void solve(int es)
{
  int br=0;
  str=0;endc=n-1;
  while(1)
  {
    if(es>tab[n-1][n-1]||str==n||endc==-1){printf("No Solution\n");return;}
    if(es<tab[str][endc]){endc--;br++;}
    if(es>tab[str][endc]){str++;br++;}
    if(tab[str][endc]==es){printf("%d\n",br);return;}
  }
}
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      scanf("%d",&tab[i][j]);
    }
  }
  scanf("%d",&k);
  for(int i=0;i<k;i++)
  {
    scanf("%d",&o);
    solve(o);
  }
  return 0;
}
