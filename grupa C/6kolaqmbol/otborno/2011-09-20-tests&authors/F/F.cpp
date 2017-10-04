#include <iostream>
using namespace std;
int main()
{
  int t, n, x, max, sum;
  cin >> t;
  for(int i=1; i<=t; i++)
  {
    cin >> n;
    max = 0; sum = 0;
    for(int j=1; j<=n; j++)
    {
      cin >> x;
      sum+=x;
      if(x>max) max=x;
    }
    cout << max*n - sum << endl;
  }
  return 0;
}
