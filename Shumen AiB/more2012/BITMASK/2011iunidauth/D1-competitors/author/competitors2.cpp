//Task: competitors
//Author: Rusko Shikov
#include <iostream>
using namespace std;

const int nmax=10;
const int kmax=20;

int n,k;
int t[nmax+1][kmax+1];

int ccount;
int ccomb[nmax+1];
bool temi[kmax+1];



void input()
{
  int i,j;
  cin >> n >> k;
  for (i=1;i<=n;i++)
  {
    cin >> t[i][0];
    for (j=1;j<=t[i][0];j++)
      cin >> t[i][j];
  }
}

bool check_ccomb()
{
  int i,j,m;
  int count_temi;
  for (i=1;i<=k;i++)
    temi[i]=false;
  for (i=1;i<=ccount;i++)
  {
    j=ccomb[i];
    for (m=1;m<=t[j][0];m++)
      temi[t[j][m]]=true;
  }
  count_temi=0;
  for (i=1;i<=k;i++)
    if (temi[i]) count_temi++;
  return (count_temi == k);
}

bool comb_gen()
{
  int i,j;
  bool flend;
  for (i=1;i<=ccount;i++)
    ccomb[i]=i;
  flend=check_ccomb();
  i=ccount;
  while ((!flend) && (i>0))
  {
    if (ccomb[i]==(n-ccount+i))
      i--;
    else
    {
      ccomb[i]++;
      for (j=(i+1);j<=ccount;j++)
        ccomb[j]=ccomb[j-1]+1;
      i=ccount;
      flend=check_ccomb();
    }
  }
  return flend;
}

void print_rez()
{
  int i;
  cout << ccount << endl;
  for (i=1;i<=(ccount-1);i++)
    cout << ccomb[i] << " ";
  cout << ccomb[ccount] << endl;
}

int main()
{
  input();
  for (ccount=1;ccount<=n;ccount++)
    if (comb_gen())
    {
      print_rez();
      break;
    }
  return 0;
}
