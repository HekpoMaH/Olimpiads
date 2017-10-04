#include<iostream>

using namespace std;

int x[1024];
int a[1024][1024], d[1024][1024];

int main()
{   
    int n, k, r, m, ans;
    cin >> n >> k;
    x[1]=0;
    for(int i=2; i<=n; i++)
      { cin >> r;
        x[i] = x[i-1] + r;
      }
    for(int i=1; i<=n; i++)
      for(int j=i; j<=n; j++)
        { a[i][j]=0;
          for(int s=i; s<=j; s++)
            { m = min(x[s]-x[i], x[j]-x[s]);
              if (m > a[i][j]) a[i][j] = m;
            }
        }

    for(int i=1; i<=k; i++)
      d[i][i] = 0;
    for(int i=2; i<=n; i++)
      d[i][1]= x[i] - x[1];
    for(int i=3; i<=n; i++)
       for(int j=2; j<i && j<=k; j++)
         { d[i][j] = d[i-1][j-1];
           for(int s = j-1; s < i-1; s++)  
             { m = max(d[s][j-1],a[s][i]);
               if (m < d[i][j]) d[i][j] = m;
             }
         }
    ans = d[n][k];
    for(int i=k; i<n; i++)
      { m = max(d[i][k], x[n]-x[i]);
        if (m < ans) ans = m;
      } 
    cout << ans << endl;  
            
    return 0;
}
