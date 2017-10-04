/*
codr: timiter
task: frog
lang: C++
*/

#include <cstdio>

using namespace std;

int n;
int x[16] = { 0 }, y[16] = { 0 };
int z[16][16];
bool u[16] = { false };

int dgin(int, int);
int razs(int, int);

int main()
{
    scanf("%d", &n);
    int i, j;
    for (i = 1; i <= 2 * n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
        u[i] = false;
        for (j = 0; j <= i; j++)
        {
            z[i][j] = z[j][i] = razs(i, j);
        }
    }

    printf("%d\n", dgin(0, 0));

    return 0;
}

int dgin(int r, int p)
{
    if (p == n)
    {
        return 0;
    }

    int s = 16384, w, i;
    u[r] = true;

    for (i = 1; i <= 2 * n; i++)
    {
        if (!u[i])
        {
            w = dgin(i, p + 1) + z[r][i];
            if (w < s)
            {
                s = w;
            }
        }
    }

    u[r] = false;

    return s;
}

int razs(int a, int b)
{

    int xs = x[a] - x[b];
    if (xs < 0)
    {
        xs = -xs;
    }

    int ys = y[a] - y[b];
    if (ys < 0)
    {
        ys = -ys;
    }

    return (xs > ys ? xs : ys);
}
