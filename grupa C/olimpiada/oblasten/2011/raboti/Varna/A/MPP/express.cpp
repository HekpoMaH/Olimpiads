/*
TASK: express
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

typedef long long ll;

const ll INF = 1000000000000000010LL;

char s[32];
int n;
bool done[32][32][2];
ll dp[32][32][2];

ll eval(int l,int r,bool fl)
{
    if(done[l][r][fl]) return dp[l][r][fl];
    if(l == r) return (s[l] - '0');

    ll res;

    if(fl == 0) res = INF;
    else res = -INF;

    for(int i=l+1;i<r;i+=2)
    {
        ll st[2][2];
        st[0][0] = eval(l , i-1 , 0);
        st[0][1] = eval(l , i-1 , 1);
        st[1][0] = eval(i+1 , r , 0);
        st[1][1] = eval(i+1 , r , 1);

        if(fl == 0)
        {
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    if(s[i] == '+')
                    {
                        if(st[0][j] + st[1][k] < res)
                            res = st[0][j] + st[1][k];
                    }
                    else if(s[i] == '-')
                    {
                        if(st[0][j] - st[1][k] < res)
                            res = st[0][j] - st[1][k];
                    }
                    else
                    {
                        if(st[0][j] * st[1][k] < res)
                            res = st[0][j] * st[1][k];
                    }
        }
        else
        {
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    if(s[i] == '+')
                    {
                        if(st[0][j] + st[1][k] > res)
                            res = st[0][j] + st[1][k];
                    }
                    else if(s[i] == '-')
                    {
                        if(st[0][j] - st[1][k] > res)
                            res = st[0][j] - st[1][k];
                    }
                    else
                    {
                        if(st[0][j] * st[1][k] > res)
                            res = st[0][j] * st[1][k];
                    }
        }
    }

    done[l][r][fl] = 1;
    dp[l][r][fl] = res;
    return dp[l][r][fl];
}

int main()
{
    scanf("%s",&s);
    n = strlen(s);
    cout << eval(0 , n-1 , 0) << endl;

    return 0;
}
