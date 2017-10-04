#include<iostream>
using namespace std;
int a[128],b[128],n;
void read()
{
  int i;
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  for(i=0;i<n;i++)
  {
    cin>>b[i];
  }
}
int  main()
{
  int i,min,max;
  read();
  min=a[0];
  max=b[0];
  for(i=1;i<n;i++)
  {
    if(min>a[i])min=a[i];
  }
  for(i=1;i<n;i++)
  {
    if(max<b[i])max=b[i];
  }
  cout<<min+max<<endl;
return 0;
}