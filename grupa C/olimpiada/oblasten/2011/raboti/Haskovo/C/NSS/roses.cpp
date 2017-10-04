#include <iostream>

using namespace std;

int m,n,k;
int a[1010][1010];
int osm = 0;
int sm[1010][1010],smup[1010][1010],smleft[1010][1010];//,smdown[1010][1010],smright[1010][1010];
int mx = -1;
int smnr,smnd;

int smnext_right (int i,int j)
{
  int summ = 0;
  for (int h = 0; h < k; h ++){
    summ += a[i + h][j + k - 1];
  }
  //cout << i << " " << j << " --> sumnext_right = " << summ << endl;
  return summ;
}
int smnext_down (int i,int j)
{
  int summ1 = 0;
  for (int h = 0; h < k; h ++){
    summ1 += a[i + k - 1][j + h];
  }
  //cout << i << " " << j << " --> sumnext_down = " << summ << endl;
  return summ1;
}

int main()
{
  cin >> m >> n >> k;
  for (int i = 0; i < m; i ++){
    for (int j = 0; j < n; j ++){
      cin >> a[i][j];
      osm += a[i][j];
    }
  }
  //cout << endl;
  for (int i = 0; i < k; i ++){
    for (int j = 0; j < k; j ++){
      if (i == 0) smup[0][0] += a[i][j];
      if (j == 0) smleft[0][0] += a[i][j];
      sm[0][0] += a[i][j];
    }
  }
  for (int i = 0; i < m; i ++){
    for (int j = 0; j < n; j ++){
      if (i > 0 || j > 0){
        if (j > 0){
          smup[i][j] = smup[i][j - 1];
          smup[i][j] -= a[i][j - 1];
          smup[i][j] += a[i][j + k - 1];
          sm[i][j] = sm[i][j - 1];
          sm[i][j] -= smleft[i][j - 1];
          sm[i][j] += smnext_right(i,j);
          smnr = smnext_right(i,j);
        }
        if (i > 0){
          smleft[i][j] = smleft[i - 1][j];
          smleft[i][j] -= a[i - 1][j];
          smleft[i][j] += a[i + k - 1][j];
          if (j == 0){
            sm[i][j] = sm[i - 1][j];
            sm[i][j] -= smup[i - 1][j];
            sm[i][j] += smnext_down(i,j);
            smnd = smnext_down(i,j);
          }
          /*if (j > 0){
            sm[i][j] -= a[i + k - 1][j];
            sm[i][j] -= a[i + k - 1][j + k - 1];
          }*/
        }
        if (j == 0){
          for (int u = 0; u < k; u ++){
            smup[i][j] += a[i][u];
          }
        }
        if (i == 0){
          for (int u = 0; u < k; u ++){
            smleft[i][j] += a[u][j];
          }
        }
      }
      if (sm[i][j] > mx) mx = sm[i][j];
      //cout << smleft[i][j] << " " << smup[i][j] << " " << smnr << " " << smnd << " " << sm[i][j] << "     ";
    }
    //cout << "\n\n\n\n\n";
  }
  //cout << osm << " " << mx << endl;
  cout << osm - mx << endl;
  return 0;
}
/*
3 4 2
1 1 1 2
2 3 4 1
2 1 9 2

5 5 3
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

5 5 3
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
*/
