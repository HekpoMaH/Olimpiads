///Task: Points
///Author: Mladen Manev
#include <bits/stdc++.h>
using namespace std;

const int M = 123456789;
int main()
{
    int n, k, a, a1, first, s = 0, b[10000];
    scanf("%d", &n);
    scanf("%d", &a);
    first = a;
    for(int i=2; i<=n; i++)
    {
        scanf("%d", &a1);
        if(a > a1) s += (a - a1);
        a = a1;
    }
    k = first - s;
    cout<<k<<endl;
    if(k < 0)
    {
        printf("0\n");
        return 0;
    }
    for(int i=0; i<=k; i++)
      b[i] = 1;
    for(int j=2; j<=n+1; j++)
      for(int i=1; i<=k; i++)
        b[i] = (b[i] + b[i-1]) % M;
    printf("%d\n", b[k]);
    return 0;
}
