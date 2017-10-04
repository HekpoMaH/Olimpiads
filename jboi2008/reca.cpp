#include<bits/stdc++.h>
using namespace std;
const int N=1024;
int n;
int a[N], b[N], t[N][2];
int main()
{
cin >> n;
for(int i=1;i<=n;i++) cin >> a[i] >> b[i];
t[1][0]=a[1]; t[1][1]=b[1];
for(int i=2;i<=n;i++)
{
t[i][0]=a[i]+
max(t[i-1][0]+abs(b[i-1]-b[i]),t[i-
1][1]+abs(a[i-1]-b[i]));
 t[i][1]=b[i]+
max(t[i-1][0]+abs(b[i-1]-a[i]),t[i-
1][1]+abs(a[i-1]-a[i]));
}
cout << max(t[n][0], t[n][1]) << endl;
}
