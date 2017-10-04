#include <iostream>
using namespace std;

const int s_max=1000001;
int s, n;
int b[s_max];

int main()
{
 cin >> s >> n;
 b[1]=1;
 for(int j=2;j<=s;j++)
   {
      int t=(j<=n?1:j);
      for(int k=1;k<=n;k++)
      {
        int v;
        if(j-k>=1) v=b[j-k]+1;
        if(v<t) t=v;
        if(k>1)if(j%k==0) v=b[j/k]+1;
        if(v<t) t=v;
      }
      b[j]=t;
   }
 cout << b[s] << endl;
}
