/*
TASK:ship
LANG:C++
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int tejest;
typedef struct {
       int t;
       int pos;
       int p;
       } tovari;
tovari tovar[10000];

bool sravni(tovari a, tovari b)
{
     if (a.t>b.t) return true;
     if (a.t==b.t && a.p>b.p) return true;
     return false;
}

void read()
{
     scanf("%d", &n);
     for (int i=0;i<n;i++) { scanf("%d", &tovar[i].t); tovar[i].pos=i; }
     for (int i=0;i<n;i++) { scanf("%d", &tovar[i].p); }
}

int main()
{
    read();
    sort(tovar,tovar+n,sravni);
    for (int i=0;i<n;i++) {
        if (tovar[i].pos==tovar[i].p) continue;
        else {
             tejest+=tovar[i].t;
             for (int j=i;j<n;j++) { if (tovar[j].pos==tovar[i].p) { tovar[j].pos=tovar[i].pos; tovar[i].p=tovar[i].pos; tejest+=tovar[j].t; } }
        }
    }
    printf("%d\n", tejest);
    return 0;
}
