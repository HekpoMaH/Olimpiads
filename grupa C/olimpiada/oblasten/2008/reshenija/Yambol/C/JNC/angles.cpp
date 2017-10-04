//TASK: angles
//LANG: C++

#include <iostream>
using namespace std;

int a[1501][1501];

int main()
{
    int n, k;
    int i, j, sum, summax;
    int s, imax, jmax;
    
    summax = INT_MIN;
    
    cin >> n >> k;
    
    for ( i = 1; i <= n + k; i++ )
        for ( j = 1; j <= n + k; j++ )
            a[i][j] = 0;
            
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= n; j++ )
            cin >> a[i][j];
            
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= n; j++ )
        {
            sum = a[i][j];
            
            for ( s = 1; s <= k; s++ )
            {
                sum = sum + a[i][j+s];
                sum = sum + a[i+s][j];
            }
            
            if ( sum > summax )
            {
                summax = sum;
                imax = i;
                jmax = j;
            }
        }
    }
    
    cout << imax << " " << jmax << endl;
}
