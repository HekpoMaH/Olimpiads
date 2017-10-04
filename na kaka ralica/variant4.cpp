#include<iostream>
using namespace std;
int a[]={1,2,3,4,5,6};
int b[]={-3,0,3,6,9,12};
int main()
{
  cout<<" a | b | x"<<endl;
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      cout<<" "<<a[i]<<" |";
      if(b[j]>=0&&b[j]<10)cout<<" ";
      cout<<b[j]<<" |";
      cout<<3*a[i]*b[j]*b[j]+a[i]*b[j] -3*a[i]*a[i]<<endl;
    }
  }
  system("pause");
  return 0;
}
