/*
codr: timiter
task: express
lang: C++
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

char s[32];
long long w, q;
int l;
int p[16];
bool u[32];

void cntr(int);
long long calc();

int main()
{
    q = (long long) pow(10.0, 18);
    w = q;
    scanf("%s", s);
    int i;
    l = strlen(s);
    for (i = 0; i < l; i++)
    {
        u[i] = false;
    }
    u[l] = true;

    cntr(0);

    cout << w << "\n";

    return 0;
}

void cntr(int n)
{
    if (n == (l - 1) / 2)
    {
        long long z = calc();
        if (z < w)
        {
            w = z;
        }
    }
    else
    {
        int i, j, k;
        for (i = 1; u[i]; i += 2);
        for (j = i; !u[j]; j += 2);
        for (k = i; k < j; k += 2)
        {
            p[n] = k;
            u[k] = true;
            cntr(n + 1);
            u[k] = false;
        }
    }
}

long long calc()
{
    long long x, y;
    long long r[32];
    int i, j;
    for (i = 0; i < l; i += 2)
    {
        r[i] = s[i] - '0';
    }
    for (i = 1; i < l; i += 2)
    {
        r[i] = q;
    }

    for (i = (l - 3) / 2; i >= 0; i--)
    {
        for (j = p[i] - 1; r[j] == q; j--);
        x = r[j];
        r[j] = q;
        for (j = p[i] + 1; r[j] == q; j++);
        y = r[j];
        r[j] = q;
        switch (s[p[i]])
        {
        case '+':
            r[p[i]] = x + y;
            break;
        case '-':
            r[p[i]] = x - y;
            break;
        case '*':
            r[p[i]] = x * y;
            break;
        }
    }

    return r[p[0]];
}
