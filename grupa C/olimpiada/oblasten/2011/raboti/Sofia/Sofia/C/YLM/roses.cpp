#include<iostream>
using namespace std;
int table [1000][1000];
long long sums [1000][1000];
int main ()
{
    int m, n, k;
    cin >> m >> n >> k;
    for(int i = 0; i < n; i ++) { cin >> table [0][i]; if ( i == 0 ) sums [0][i] = table [0][i]; else sums [0][i] = sums [0][i-1] + table [0][i]; }
    for(int i = 1; i < m; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            cin >> table [i][j];
            if(j == 0) sums [i][j] = sums [i-1][0] + table [i][0];
            else {
                sums [i][j] = sums [i-1][j] + sums [i][j-1] - sums [i-1][j-1] + table [i][j];
            }
        }
    }
    long long maxx = -1;
    for(int i = k - 1; i < m; i ++)
    {
        for(int j = k - 1; j < n; j ++)
        {
             if( j == k - 1 )
             {
                if( i == k - 1 ) { if(maxx < sums [i][j]) maxx = sums[i][j]; } else { if(maxx < sums[i][j] - sums[i-k][j]) maxx = sums[i][j] - sums[i-k][j]; }
             }
             else {

               if( i == k - 1) {
                    if( maxx < sums[i][j] - sums [i][j-k]) maxx = sums[i][j] - sums[i][j-k];
                 }
                 else {
                      if( maxx < sums[i][j] - sums [i-k][j] - sums[i][j-k] + sums [i-k][j-k]) maxx = sums[i][j] - sums [i-k][j] - sums[i][j-k] + sums [i-k][j-k];
                 }


             }
        }

    }
    cout << sums [m-1][n-1] - maxx << endl;
    return 0;
}