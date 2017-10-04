/*
codr: timiter
task: pircos
lang: C++
*/

#include <cstdio>

using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    int a[101000];
    int i, j, k, l;
    for (i = 0; i <= 100050; i++)
    {
        a[i] = -1;
    }
    for (l = 0; l < n; l++)
    {
        scanf("%d", &k);
        for (j = 0; a[j] != k && j < 100050; j++);
        if (j == 100050)
        {
            for (j = 0; a[j] != -1; j++);
            a[j] = k;
        }
        else
        {
            a[j] = -1;
        }
    }
    for (i = 0; a[i] == -1; i++);
    j = a[i];
    for (i = 100050; a[i] == -1; i--);
    k = a[i];
    if (j < k)
    {
        printf("%d %d\n", j, k);
    }
    else
    {
        printf("%d %d\n", k, j);
    }

    return 0;
}
