//Task: safecode
//Author: Pavel Petrov
#include <iostream>
#include <string>
using namespace std;

int tab[15][15];
bool sum[57];
int c1,c2,c3,c4,sum1,sum2;
string s;

void init()
{
  int i;

  tab[0][0]=1;
  tab[0][1]=0;

  tab[1][0]=8;
  tab[1][1]=0;
  tab[1][2]=1;
  tab[1][3]=3;
  tab[1][4]=5;
  tab[1][5]=7;
  tab[1][6]=9;
  tab[1][7]=11;
  tab[1][8]=13;

  tab[2][0]=8;
  tab[2][1]=0;
  tab[2][2]=2;
  tab[2][3]=3;
  tab[2][4]=6;
  tab[2][5]=7;
  tab[2][6]=10;
  tab[2][7]=11;
  tab[2][8]=14;

  tab[3][0]=4;
  tab[3][1]=0;
  tab[3][2]=3;
  tab[3][3]=7;
  tab[3][4]=11;

  tab[4][0]=8;
  tab[4][1]=0;
  tab[4][2]=4;
  tab[4][3]=5;
  tab[4][4]=6;
  tab[4][5]=7;
  tab[4][6]=12;
  tab[4][7]=13;
  tab[4][8]=14;

  tab[5][0]=4;
  tab[5][1]=0;
  tab[5][2]=5;
  tab[5][3]=7;
  tab[5][4]=13;

  tab[6][0]=4;
  tab[6][1]=0;
  tab[6][2]=6;
  tab[6][3]=7;
  tab[6][4]=14;

  tab[7][0]=2;
  tab[7][1]=0;
  tab[7][2]=7;

  tab[8][0]=8;
  tab[8][1]=0;
  tab[8][2]=8;
  tab[8][3]=9;
  tab[8][4]=10;
  tab[8][5]=11;
  tab[8][6]=12;
  tab[8][7]=13;
  tab[8][8]=14;

  tab[9][0]=4;
  tab[9][1]=0;
  tab[9][2]=9;
  tab[9][3]=11;
  tab[9][4]=13;

  tab[10][0]=4;
  tab[10][1]=0;
  tab[10][2]=10;
  tab[10][3]=11;
  tab[10][4]=14;

  tab[11][0]=2;
  tab[11][1]=0;
  tab[11][2]=11;

  tab[12][0]=4;
  tab[12][1]=0;
  tab[12][2]=12;
  tab[12][3]=13;
  tab[12][4]=14;

  tab[13][0]=2;
  tab[13][1]=0;
  tab[13][2]=13;

  tab[14][0]=2;
  tab[14][1]=0;
  tab[14][2]=14;

  for (i=0;i<=56;i++)
    sum[i]=false;

}

void input()
{
  int i,j,a;
  cin >> s;
  if (s[0]<='9') c1=s[0]-'0';
  else c1=s[0]-'A'+10;
  if (s[1]<='9') c2=s[1]-'0';
  else c2=s[1]-'A'+10;
  if (s[2]<='9') c3=s[2]-'0';
  else c3=s[2]-'A'+10;
  if (s[3]<='9') c4=s[3]-'0';
  else c4=s[3]-'A'+10;
  if (s[4]<='9') sum1=s[4]-'0';
  else sum1=s[4]-'A'+10;
  if (s.length()>5)
    if (s[5]<='9') sum2=s[5]-'0';
    else sum2=s[5]-'A'+10;
  else
    {
      sum2=sum1;
      sum1=0;
    }
  for (i=1;i<=tab[sum1][0];i++)
    for (j=1;j<=tab[sum2][0];j++)
    {
      a=tab[sum1][i]*15+tab[sum2][j];
      if (sum1>0)
        if ((a>14) && (a<=56))
          sum[a]=true;
      if (sum1==0)
        if ((a>0) && (a<=56))
          sum[a]=true;
    }
}
int main()
{
  int i1,i2,i3,i4,a,count=0;
  init();
  input();
  for (i1=1;i1<=tab[c1][0];i1++)
    for (i2=1;i2<=tab[c2][0];i2++)
      for (i3=1;i3<=tab[c3][0];i3++)
        for (i4=1;i4<=tab[c4][0];i4++)
        {
          a=tab[c1][i1]+tab[c2][i2]+tab[c3][i3]+tab[c4][i4];
          if (sum[a]) count++;

        }
  cout << count << endl;
  return 0;
}
