/*
TASK: distance
LANG: C++
*/

/* ID: Alexander Georgiev */
#include <cstdio>
#include <cstring>

#define MAX 1 << 21

using namespace std;
FILE *in; FILE *out;

unsigned int dyn[MAX];
int a[32][2];
int maxlevel, n;


unsigned int recurse(int mask, int level, int lastbit)
{
int i, c;
unsigned int cur, best;

if (level >= maxlevel) return 0;
if (dyn[mask] != (unsigned int)(-1)) return dyn[mask];

best = 0; cur = 0;

for (i=0; i<n-1; i++) if ((mask & (1 << i)) == 0)
    {
    for (c=i+1; c<n; c++) if ((mask & (1 << c)) == 0)
        {
        if (c == n-1 && lastbit == 1) continue;
        
        if (c < n-1) cur = recurse(mask | (1 << i) | (1 << c), level + 1, lastbit);
        else cur = recurse(mask | (1 << i), level + 1, 1);
        
        cur += (a[i][0] - a[c][0]) * (a[i][0] - a[c][0]);
        cur += (a[i][1] - a[c][1]) * (a[i][1] - a[c][1]);
        
        if (best < cur) best = cur;
        }
    }

dyn[mask] = best;
return best;
}


int main(void)
{
int i;
unsigned int ans;

memset(dyn, -1, sizeof(dyn));

in = fopen("distance.in", "rt");
out = fopen("distance.out", "wt");

fscanf(in, "%d", &n); maxlevel = n/2;
for (i=0; i<n; i++) fscanf(in, "%d %d", &a[i][0], &a[i][1]);

ans = recurse(0, 0, 0);
fprintf(out, "%u.000\n", ans);

fclose(in); fclose(out);
return 0;
}
