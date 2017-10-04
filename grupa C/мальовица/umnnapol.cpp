#include<iostream>
using namespace std;
int a[100],b[100],st1,st2,s[10000],k;
int main()
{
  cin>>st1;
  for(int i=0;i<=st1;i++)cin>>a[i];
  cin>>st2;
  for(int j=0;j<=st2;j++)cin>>b[j];
  for(int i=0;i<=st1;i++)
  {
    for(int j=0;j<=st2;j++)
    {
      k=i+j;
      s[k]+=a[i]*b[j];
    }
  }
  for(int i=0;i<=st1+st2;i++)cout<<s[i]<<" ";
  cout<<endl;
  return 0;
}
