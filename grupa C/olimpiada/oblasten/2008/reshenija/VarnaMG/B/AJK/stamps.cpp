#include <cstdio>
#include <algorithm>
#define MAXN 3000
using namespace std;

unsigned a[MAXN], n, sum, s, br, mintemp;


bool cmp(int a, int b)
{  
     if (a > b) return 1;
     return 0;
}
     

void rec(int ind)
{
     if (br > mintemp) return;
     if (ind >= n) {
             unsigned k = s - sum + br;
             if (k < mintemp) mintemp = k;
             return;
     }
     unsigned k = (s - sum)/a[ind];
     while (k >= 0 && k*a[ind] <= s) {
           sum += k*a[ind];
           br += k;
           
           rec(ind + 1);
           
           sum -= k*a[ind];
           br -= k;
           k--;
     }                            
     
     return;
}
int main()
{
    unsigned i;
    scanf("%u%u", &s, &n);

    for (i = 0; i < n; ++i) {
        scanf("%u", &a[i]);
        if (a[i] == 1) i--;
    }
    n -= 1;
    sort(a, a + n, cmp);
    

    br = 0;
    sum = 0;
    mintemp = s;
    rec(0);
    printf("%u\n", mintemp);
       
    return 0;
}
