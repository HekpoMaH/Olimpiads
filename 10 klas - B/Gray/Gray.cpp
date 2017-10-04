#include <stdio.h>
#define N 4
#define K 3
main()
{
    int n[K+1]; /* the maximum for each digit */
    int g[K+1]; /* the Gray code */
    int u[K+1]; /* +1 or -1 */
    int i, j, k;
    for (i=0; i<=K; i++) {g[i]=0; u[i]=1; n[i]=N;};
    while (g[K]==0) {
    printf("(");
    for (j=K-1; j>=0; j--) printf (" %d", g[j]);
    printf (")\n");

    i=0; /* enumerate next Gray code */
    k=g[0]+u[0];
    while ((k>=n[i]) || (k<0)) {
    u[i]=-u[i];
    i++;
    k=g[i]+u[i];
    };
    g[i]=k;
    };
}