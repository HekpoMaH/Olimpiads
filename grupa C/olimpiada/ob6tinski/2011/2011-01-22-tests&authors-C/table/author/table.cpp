#include<iostream>
using namespace std;

int m, n, k, v, c=0, s=0;

int main()
{
  cin >> m >> n >> k;
  for(int i=1;i<=m;i++)
  for(int j=1;j<=n;j++)
   { cin >> v; c++;
     if(c%k==0) s += v;
   }
  cout << s << endl;

}
