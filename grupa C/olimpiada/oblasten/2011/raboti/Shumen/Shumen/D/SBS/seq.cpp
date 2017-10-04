#include<iostream>
using namespace std;
int main ()
{
  double a,max=0;
  int br=0,maxbr=0;
  do
  {
    cin>>a;
    if (a>=max)
    {
      max=a;
      br++;
    }
    if (br>maxbr)
    maxbr=br;
    else if (a!=0&&a<max)
    {
      br=1;
    }
  }
  while (a!=0);
  cout<<maxbr<<endl;
  return 0;
}