// O(n^5)

#include <cstdio>

const int nmax=2000;

int wall[nmax+2][nmax+2];

int n;

void input()
{
  int i,j;  
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      scanf("%d", &wall[i][j]);
  
}

int checkrectangle(int xul, int yul, int xdr, int ydr)
{
  int i,j;  
  
  // Проверка дали лявата, вертикална линия на прозореца разполовява правоъгълниче; ако да, то връща -1
  for (i=xul;i<=xdr;i++)
    if (wall[i][yul]==wall[i][yul-1]) return -1;
  //Проверка дали горната, хоризонтална линия на прозореца разполовява правоъгълниче; ако да, то връща -2
  for (j=yul;j<=ydr;j++)
    if (wall[xul][j]==wall[xul-1][j]) return -2;
  // Проверка дали дясната, вертикална линия на прозореца разполовява правоъгълниче, ако да, то връща -3
  for (i=xul;i<=xdr;i++)
    if (wall[i][ydr]==wall[i][ydr+1]) return -3;
  // Проверка дали долната, хоризонтална линия на прозореца разполовява правоъгълниче; ако да, то връща -4
  for (j=yul;j<=ydr;j++)
    if (wall[xdr][j]==wall[xdr+1][j]) return -4;
    
  // Това е правоъгълник, който съдържа само цели правоъгълничета. Изчисляваме лицето му
  
  return (xdr-xul+1)*(ydr-yul+1);         
}

int main() {
  int iul, jul, idr, jdr;  
  int smax=0, iulmax, julmax, idrmax, jdrmax;
  input();
  for (iul=2;iul<n;iul++)
    for (jul=2;jul<n;jul++)
      for (idr=iul;idr<n;idr++)
        for (jdr=jul;jdr<n;jdr++)
          {
             int s= checkrectangle(iul,jul,idr,jdr);             
             if (s>smax)
             {
                smax=s;
                iulmax=iul;julmax=jul;
                idrmax=idr;jdrmax=jdr; 
             }
          }
   printf("%d %d %d %d %d\n",smax, iulmax, julmax, idrmax, jdrmax);     
  
  
  return 0;

}

/*
6
1 1 4 4 13 14
2 3 3 5 13 14
2 6 7 5 12 12
9 6 7 10 10 15
9 8 8 11 11 15
16 16 17 17 18 18
*/
