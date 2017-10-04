#include <iostream>
using namespace std;

bool positions[1000001];
char ans[101];

void fillpositions()
{
  int i,k;
  positions[0] = false;
  positions[1] = true;
  positions[2] = true;
  for (i=3;i<=1000000;i++)
  {
    k = i%3;
    switch (k)
    {
      case 0:
        if (positions[i-1] && positions[i-2])
          positions[i] = false;
        else
          positions[i] = true;
        break;
      case 1:
        if (positions[i-1] && positions[i-3])
          positions[i] = false;
        else
          positions[i] = true;
        break;
      case 2:
        if (positions[i-1] && positions[i-2] && positions[i-3])
          positions[i] = false;
        else
          positions[i] = true;
        break;

    }

  }
}

int main()
{
  int n,m,k;
  fillpositions();
  cin >> n ;
  for (k=1;k<=n;k++)
  {
    cin >> m;
    if  (positions[m])
      ans[k] = '1';
    else
      ans[k] = '2';
  }
  for (k=1;k<=n;k++)
    cout << ans[k];
  cout << endl;

  return 0;
}

