#include <iostream>
using namespace std;

bool a[1000][30][30];

bool simcomp(int r, int s, int n)
{
     for(int i = 0; i < n; i++)
             for(int j = 0; j < n; j++)
                     if(a[r][i][j] != a[s][i][j])
                                   return false;
     return true;
}

void rotate_cw(int r, int n)
{
     bool v[30][30];
     for(int i = 0; i < n; i++)
             for(int j = 0; j < n; j++)
                     v[j][n - i] = a[r][i][j];
     for(int i = 0; i < n; i++)
             for(int j = 0; j < n; j++)
                     a[r][i][j] = v[i][j];
     return;
}

bool comp(int r, int s, int n)
{
     if(simcomp(r, s, n) == true)
                   return true;
     rotate_cw(r, n);
     if(simcomp(r, s, n) == true)
                   return true;
     rotate_cw(r, n);
     if(simcomp(r, s, n) == true)
                   return true;
     rotate_cw(r, n);
     if(simcomp(r, s, n) == true)
                   return true;
     return false;
}

void cpy(int m, int n, int s)
{
     for(int i = 0; i < n; i++)
             for(int j = 0; j < s; j++)
                     a[n][i][j] = a[m][i][j];
     return;
}

int main()
{
    char q;
    int m, n, max = 0;
    bool t = false;
    cin >> m >> n;
    for(int i = 0; i < m; i++)
    {
            for(int j = 0; j < n; j++)
                    for(int z = 0; z < n; z++)
                    {
                            cin >> q;
                            a[0][j][z] = (int)q - (int)'0';
                    }
            for(int j = 1; j <= max; j++)
            {
                    if(comp(0, j, n) == true)
                    {
                               t = true;
                    }
            }
            if(t != true)
            {
                 ++max;
                 cpy(0, max, n);
            }
            t = false;
    }
    cout << max << endl;
    return 0;
}
