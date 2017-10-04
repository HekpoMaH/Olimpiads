#include<iostream>
using namespace std;
int a[100],b[100],st1,st2,ch[200],f,k;
int main()
{
  cin>>st1;
  for(int i=0;i<=st1;i++)cin>>a[i];
  cin>>st2;
  for(int j=0;j<=st2;j++)cin>>b[j];
  do
  {
    ch[k]=a[0]/b[0];
    for(int i=1;i<=st2;i++)a[i-1]=a[i]-b[i]*ch[k];
    if(st1>st2)
    {
      for(int i=st2+1;i<=st1;i++)a[i-1]=a[i];
      st1--;k++;
      cout<<"A"<<endl;
    }
    else f=1;
  }while(f==0);
  for(int i=0;i<=k;i++)cout<<ch[i]<<" ";
  cout<<endl;
  for(int i=0;i<=st1-1;i++)cout<<a[i]<<" ";
  return 0;
}
