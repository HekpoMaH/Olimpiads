/*
TASK:maxi
LANG:C++
*/

#include<iostream>

using namespace std;

int a[20][20];

int main()
{   int maxi=0;
    int m, n;
    
    cin >> m >> n;
    for(int i=1; i<=m; i++)
      for(int j=1; j<=n; j++)
        cin >> a[i][j];
         
    for(int i=1; i<=m; i++)
      for(int j=1; j<=n; j++)
        { int s1, s2, s3, s4, s5, s6;
          s1 = a[i][j] + a[i][j+1] + a[i+1][j];
          s2 = a[i][j] + a[i][j+1] + a[i+1][j+1];
          s3 = a[i][j] + a[i+1][j] + a[i+1][j+1];
          s4 = a[i][j+1] + a[i+1][j] + a[i+1][j+1];
          s5 = a[i][j] + a[i][j+1] + a[i][j+2];
          s6 = a[i][j] + a[i+1][j] + a[i+2][j];
          if (s1 > maxi) maxi = s1;
          if (s2 > maxi) maxi = s2;
          if (s3 > maxi) maxi = s3;
          if (s4 > maxi) maxi = s4;
          if (s5 > maxi) maxi = s5;
          if (s6 > maxi) maxi = s6;
      }
    cout << maxi << endl;
    return 0;
}    
