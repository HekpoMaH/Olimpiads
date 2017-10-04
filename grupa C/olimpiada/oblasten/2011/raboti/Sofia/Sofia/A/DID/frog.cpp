#include<iostream>
#include<algorithm>
using namespace std;
short dots;
short Matrix [1000][1000];
int steps=0;
short maxX,minX,maxY,minY;
short N;
int rec(short x,short y,short dots)
{
  steps++;
  //cout << "X : "<< x << "Y : " << y <<"\n";
  //system("pause");
  if (!dots && (x > 1000) || (x < -1000) )
    return 0;
  if (!dots && (y > 1000) || (y < -1000) )
    return 0;
  if (( (x > maxX) || (x < minX) ) )
  {
   //cout << "X out of bounds\n";
   return 0;
  }
  if (( y > maxY || y < minY ))
  {
   //cout << "Y out of bounds\n";
   return 0;
  }
  if (( Matrix[x][y] >= dots ) && Matrix[x][y])
  {
    Matrix[x][y] = dots+1;
    //cout << "Passed already\n";
    return 0;
  }
  if  ( Matrix[x][y] == -1 )
    dots++;
  else
  {
    Matrix[x][y] = dots+1;
  }
  if(N == dots)
  {
   // cout << "Steps : "<< steps <<"\n";
    if (steps == 3)
      system("pause");
    return steps;
  }
  int st[4];

  short save = Matrix[x+1][y+1];
  st[0]=rec(x+1,y+1,dots);
  Matrix[x+1][y+1] = save;
  steps--;
  dots--;
  save = Matrix[x+1][y-1];
  st[1] = rec(x+1,y-1,dots);
  Matrix[x+1][y-1] = save;
  steps--;
  dots--;
  save = Matrix[x-1][y+1];
  st[2] = rec(x-1,y+1,dots);
  Matrix[x-1][y+1] = save;
  steps--;
  dots--;
  save = Matrix[x-1][y-1];
  st[3] = rec(x-1,y-1,dots);
  Matrix[x-1][y-1] = save;
  steps--;
  dots--;
  sort(&st[0],&st[4]);
  short i;
  for(i =0;!st[i] && i<=3;i++);
  return st[i];
}
int main()
{
  cin >> N;
  for (short i = 0; i < 1000; i++)
    for (short j = 0; j < 1000; j++)
      Matrix[i][j] = 0;
  for (short i = 0; i < 2*N; i++)
  {
    short x,y;
    cin >> x >> y;
    if ((maxX < x)|| !i)
      maxX = x;
    if ((maxY < y)|| !i)
      maxY = y;
    if ((minX > x)|| !i)
      minX = x;
    if ((minY > y)|| !i)
      minY = y;
    Matrix[x][y] = -1;
  }
  int Res = rec(1,1,0);
  cout << Res << "\n";
  return 0;
}
