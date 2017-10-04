#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 101;
int a[MAX][MAX];
int b[MAX*MAX], c[MAX*MAX];
int n, p;

void init()
{
  for(int i = 0; i < n; i++)
   for(int j = 0; j < n; j++)
     cin >> a[i][j];
}

void diag()
{
 int i, j, k = 0;
 for(i = 0; i < n; i++)
 { for(j = 0; j <= i; j++)
    {b[k] = a[j][i-j]; k++;}
 }

 for(i = n; i < 2*n-1; i++)
  { for(j = i-n+1; j < n; j++)
     {b[k] = a[j][i-j]; k++;}
  }
}


void copy(int v)
{
  for(int i = 0; i < v; i++) c[i] = b[i];
}


int main()
{
    cin >> n >> p;
    init();
    diag();

    int nb = n*n;
    int m = (nb*p) / 100;
    copy(nb);

    sort(b,b+nb);
    for(int i=0;i<n*n;i++)cout<<b[i]<<" ";
    cout<<endl;
    for(int i=0;i<n*n;i++)cout<<c[i]<<" ";
    cout<<endl;
    int k = b[m-1];
    cout<<m<<" "<<k<<endl;
    cout<<c[14-1]<<endl;
    int q;
    for(int i=0; i < nb; i++)
     if (c[i] >= k) q = i+1;
    cout << q << endl;
}
