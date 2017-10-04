/*
TASK: ninja
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int MAXN = 1510;
const int INF = 1 << 30;

int n;
bool r[MAXN];
int dp0[MAXN], dp1[MAXN];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            scanf("%d", &r[j]);

            if(!i && !j) {
                dp1[j] = 1;
                continue;
            }

            int c1 = INF, c2 = INF;
            if(j) {
                c1 = dp1[j - 1] + 1;
                if(dp1[j - 1] % 2 && !r[j]) c1 ++;
                if(dp1[j - 1] % 2 == 0 && r[j]) c1 ++;
            }

            if(i) {
                c2 = dp0[j] + 1;
                if(dp0[j] % 2 && !r[j]) c2 ++;
                if(dp0[j] % 2 == 0 && r[j]) c2 ++;
            }

            if(c1 < c2) dp1[j] = c1;
            else dp1[j] = c2;
        }
        memcpy(dp0, dp1, sizeof(dp1));
    }

    printf("%d\n", dp0[n - 1]);

    return 0;
}
