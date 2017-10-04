#include<iostream>
using namespace std;
int a[105],b[105],n,mx;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  b[0]=1;
  for(int i=1;i<n;i++)
  {
    mx=0;
    for(int j=i-1;j>=0;j--)
    {
      if(a[j]<a[i]&&b[j]>mx)mx=b[j];
    }
    b[i]=mx+1;
  }
  mx=0;int ind,tb;
  for(int i=0;i<n;i++)
  {
    //cout<<b[i]<<endl;
    if(b[i]>mx){mx=b[i];ind=i;}
  }
  cout<<mx<<endl;//<<endl;
  cout<<a[ind]<<" ";
  tb=b[ind]-1;//cout<<"tb="<<tb<<endl;
  for(int i=ind-1;i>=0;i--)
  {
    if(b[i]==tb&&a[i]<a[ind])
    {
      cout<<a[i]<<" ";
      ind=i;
      tb--;
    }
  }
  cout<<endl;
  return 0;
}
