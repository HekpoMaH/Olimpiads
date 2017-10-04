#include<iostream>
using namespace std;

int n,k;
const int N=1001;
const int K=1001;
int a[N];
int d[N][N];

int main()
{
  cin >> n >> k;
  for(int i=1;i<=n;i++) cin >> a[i];
  
  for(int j=0;j<k;j++) d[1][j] = (a[1]%k==j)?1:0;
  
  for(int i=2;i<=n;i++)
  for(int j=0;j<k;j++)
  {
    int r=a[i]%k;
    int p=j-r;
    if(p<0) p += k;
    int m=0;
    for(int t=1;t<i;t++)
     if(d[t][p]>m) m=d[t][p];
    if(m>0) d[i][j]=m+1;
    else d[i][j]=(a[i]%k==j)?1:0;           
  }
  int m=0;
  for(int i=1;i<=n;i++)
  if(d[i][0]>m) m=d[i][0];
  cout << m << endl;
}

