#include<iostream>
using namespace std;
int a[101],br,n;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=n-2;i>=0;i--)
  {
    if(a[i]>a[i+1])a[i]=a[i+1];
    else br++;
  }
  cout<<br+1<<endl;
  return 0;
}
