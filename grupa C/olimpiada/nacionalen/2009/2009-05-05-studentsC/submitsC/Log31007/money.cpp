/*
TASK:money
LANG:C++
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long x[200000],br,tekbr[200000],doh[200000];

void read()
{
     scanf("%d", &n);
     for (int i=0;i<n;i++)
         scanf("%ld", &x[i]);
}

int main()
{
    read();
    sort(x,x+n);
    for (int i=0;i<n-1;i++) {
        doh[i]=x[i]+x[i+1];
    }
    int j=0;
    for (int i=0;i<n;i++) {
        if (doh[j]<x[i]) { tekbr[j]=i-j; if (tekbr[j]>br) br=tekbr[j]; j++; }
    }
    for (;j<n-1;j++) { tekbr[j]=n-j; if (tekbr[j]>br) br=tekbr[j]; }
    if (br==2) br=1;
    printf("%ld\n", br);
    return 0;
}
