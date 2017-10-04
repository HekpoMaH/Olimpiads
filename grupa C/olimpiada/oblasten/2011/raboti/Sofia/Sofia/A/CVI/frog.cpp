#include <iostream>
using namespace std;

int n,a[15][15];
int b[15][2];
int e = 100000000;

void calculate(int x, int y)
{
     int p,q;
     p=b[x][0]-b[y][0];
     q=b[x][1]-b[y][1];
     if (p<0) p*=-1;
     if (q<0) q*=-1;
     p=max(p,q);
     a[x][y]=p;
     return;
}

void DFS(int pos, int num, int steps)
{
     if (num == n)
     {
          e=min(e,steps);
          return;
     }

     for (int i=0;i<=2*n;i++)
     {
          if (a[pos][i] != 0)
          {
               int temp = a[pos][i];
               int temp2[15];

               for (int j=0;j<=2*n;j++)
               {
                    temp2[j] = a[j][pos];
                    a[j][pos] = 0;
               }
               a[pos][i] = 0;
               a[i][pos] = 0;

               DFS(i,num+1,steps+temp);

               a[pos][i] = temp;
               a[i][pos] = temp;
               for (int j=0;j<=2*n;j++)
               {
                    a[j][pos] = temp2[j];
               }
          }
     }
     return;
}

int main()
{
     cin >> n;

     int x,y;
     b[0][0] = 0;
     b[0][1] = 0;
     for (int i=1;i<=2*n;i++)
     {
          cin >> b[i][0] >> b[i][1];
     }

     for (int i=0;i<=2*n;i++)
          for (int j=0;j<=2*n;j++)
               calculate(i,j);

     DFS(0,0,0);
     cout << e << '\n';
     return 0;
}
