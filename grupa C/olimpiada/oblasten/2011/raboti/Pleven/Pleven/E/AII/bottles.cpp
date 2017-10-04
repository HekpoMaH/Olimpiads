#include <iostream>

using namespace std;

int main()
{
  int m,n,del=10,ch;
  cin>>m>>n;
  while (1)
  {ch=del*m+del*n;
  del++;
  if ((ch%n)>=1&&(ch%m)>=0) break;
  }
  cout<<del<<endl;
    return 1;
}
