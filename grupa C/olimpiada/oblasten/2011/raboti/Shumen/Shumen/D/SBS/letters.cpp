#include<iostream>
using namespace std;
int main ()
{
  int i,n,br1=0,br2=0,br3=0,br4=0,m=1;
  char c,inter;
  string s;
  cin>>n;
  cin.get (inter);
  cin.get (c);
  for (i=0; i<=n; i++)
  {
    getline (cin,s);
    if (s[0]==c||s[0]==char (c-32))
    {
      br1++;
    }
    else if (s[n]==c||s[n]==char (c-32))
    {
      br4++;
    }
  }
  cout<<br1<<' '<<br2+1<<' '<<br3+2<<' '<<br4+2<<endl;
  return 0;
}