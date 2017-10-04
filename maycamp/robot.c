#include<iostream>
using namespace std;
int main()
{
  int a[8];
  cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
  for(int i=1;i<5;i++)
  {
    for(int j=1;j<=5-i;j++)
    {
      if(a[j]>a[j+1]){swap(a[j],a[j+1]);cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5]<<endl;}
    }
    if(a[1]<a[2]&&a[2]<a[3]&&a[3]<a[4]&&a[4]<a[5])break;
  }
  return 0;
}
