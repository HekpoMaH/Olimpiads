#include <iostream>
using namespace std;
int n, m, a[1001][1001];

void calculate()
{
    for (int i=1; i<=n; i++) a[i][1]=a[1][i]=1;
    for (int i=2; i<=n; i++)
        for (int j=2; j<=m; j++)
            if (i==j) a[i][j]=1+a[i][j-1];
            else  if (i<j) a[i][j]=a[i][i];
                  else a[i][j]=a[i][j-1]+a[i-j][j];
}
int main()
{
    cin >> n >> m;
    calculate();
    cout << a[n][m] << endl;
    return 0;
}
