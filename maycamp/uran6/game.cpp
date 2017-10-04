#include<iostream>
#include<string>
using namespace std;
int a[2000006],n,br,s,mn=9999999,sum;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  //br=1;
  for(int i=0;i<n-1;i++)
  {
    a[n+i]=a[i];
  }
  for(int i=0;i<n;i++)
  {
    sum=0;
    //for(int j=0;j<n;j++)b[j]=a[i];
    for(int j=i;j<i+n;j++)
    {
      s+=sum/2;s+=sum%2;
      sum+=a[j];
    }
    if(s<mn)mn=s;
  }
  cout<<mn<<endl;
  return 0;
}
