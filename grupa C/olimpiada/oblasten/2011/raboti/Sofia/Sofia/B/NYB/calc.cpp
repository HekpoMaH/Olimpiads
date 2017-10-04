#include <cstdio>

int n,s;
int d[1000002];

int main()
{
    scanf("%d %d", &s, &n);
    for (int i=1;i<=n;i++) {
        d[i]=1;
    }
    int sum, pr;
    for (int i=1;i<s;i++) {
        for (int j=1;j<=n;j++) {
            sum=i+j;
            pr=i*j;
            if (sum<=s) {
                if (d[sum]>d[i]+1 || d[sum]==0) {
                    d[sum]=d[i]+1;
                }
            }
            if (pr<=s) {
                if (d[pr]>d[i]+1 || d[pr]==0) {
                    d[pr]=d[i]+1;
                }
            }
        }
    }
    printf("%d\n", d[s]);
    return 0;
}
