#include <iostream>

using namespace std;

long long s;
int n;
int a[110];
bool used[110];
int br = 0;
int mn = -1;

int findmax()
{
  int mx = -1;
  for (int i = 0; i < n; i ++){
    if (a[i] > mx && used[i] == false) mx = i;
  }
  return mx;
}

void rec(int v,int ss)
{
  //cout << a[v] << " ";
  int brv = ss / a[v];
  int ost = ss - (brv * a[v]);
  //cout << brv << " ";
  used[v] = true;
  //for (int i = brv; i >= 330; i --){
    if (v > 0) rec (v - 1,ost);
    br += brv;
    //cout << br << endl;
    if (br > mn && br != 0) mn = br;
  //}
  //cout << mn << endl;
  return;
}

int main()
{
  cin >> s >> n;
  for (int i = 0; i < n; i ++) cin >> a[i];
  sort(a,a + n);
  int brmax = s / a[n - 1];
  rec (n - 1,s);
  cout << mn << endl;
  return 0;
}
/*
10000 7
12 1 11 30 14 2 18
*/
