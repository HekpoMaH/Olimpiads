#include <iostream>
using namespace std;
int main()
{
  double a,b;
  int k=1,maxk=1;

  cin>>a;

  do
  {
    cin>>b;
    if (b!=0)
    {
      if (a<=b)
      {
        k++;
      }
      else
      {
        k=1;
      }

      if (k>maxk)
      {
        maxk=k;
      }
      a=b;
    }

  }while (b!=0);

  cout<<maxk<<endl;

  return 0;
}


