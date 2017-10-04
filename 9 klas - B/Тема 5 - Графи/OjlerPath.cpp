#include <iostream>
using namespace std;
int g[101][101], p[101];
int m, n, a, b, br=0, i, j, U1, U2;
int main ()
{
   cin >> n >> m;
   for (i = 1; i <=m; i++)
   {
       cin >> a >> b;
       g[a][0]++;
       g[b][0]++;
       g[a][g[a][0]]=b;
       g[b][g[b][0]]=a;
   }
   U1 = 1; U2 = m+1;
   for (i = 1; i <=n; i++)
   if (g[i][0]%2==1)
   {
       br++;
       if (br==1)p[U1]=i;//първият нечетен става начало на пътя
   }
   if (br==0)p[U1]=1; //ако всички са четни, избираме произволен връх за начало
   if (br>2) {cout << "No way" << endl; return 0;}
   while (U1!=U2)
   {
        if (g[p[U1]][0]== 0)
        {
            p[U2]=p[U1];
            U2--;
            U1--;
        }
        else
        {
            p[U1+1] = g [p[U1]][g[p[U1]][0]]; //последния съсед
            g [p[U1]][g[p[U1]][0]] = 0;
            g[p[U1]][0]--;
            for (i = 1; i <=g[p[U1+1]][0]; i++)
                if (g[p[U1+1]][i]==p[U1])
                {
                    //for (j = i+1; j<=g[p[U1+1]][0]; j++) g[p[U1+1]][j-1] = g[p[U1+1]][j]; //преместване вляво
                    g[p[U1+1]][i]=g[p[U1+1]][g[p[U1+1]][0]];//размяна с последния
                    g [p[U1+1]][g[p[U1+1]][0]]=0;
                    g[p[U1+1]][0]--;
                }
           U1++;
        }
    }
    for (i = 1; i <= m ; i++)  cout << p[i]<<" ";
    cout << p[m+1] << endl;
    return 0;
}
/*
8 12
1 2 1 3 2 5 2 6 3 4 3 7 3 8 4 5 5 6 5 8 6 8 7 8
*/
