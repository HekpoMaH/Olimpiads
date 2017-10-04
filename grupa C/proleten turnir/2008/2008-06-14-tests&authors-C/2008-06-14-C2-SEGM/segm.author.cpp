#include<iostream>

using namespace std;

const int MAXN = 50010;

bool x[MAXN], y[MAXN];

int main()
{  int n, a, b, c;
   cin >> n >> a >> b >> c;
   for(int i=0; i <= n; i+= a)
     x[i] = true;
   for(int i=n; i >= 0; i-= b)
     x[i] = true;
   for(int i=0; i <= n-c; i++)
     if (x[i] && x[i+c])
       for(int j=i; j<i+c; j++)
         y[j] = true;
   int ans = 0;
   for(int i=0; i<n; i++)
     if (!y[i]) ans++;
   cout << ans << endl;
   return 0;
}
       
       
     
