#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n],br0=0,br1=0;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    if(a[i]==0)br0++;
  }
  if(br0%2==1){cout<<-1<<endl;return 0;}
  int l=1;int i=-1;
  while(l)
  {
    i++;
    if(i==n)i=0;
    if(a[i]==0){a[i]=1;br1++;if(a[i+1]==0)a[i+1]=1; else{if(i+1>n)a[0]=0;else a[i+1]=0;}}
    l=0;
    for(int j=0;j<n;j++)if(a[j]==0){l=1;break;}
  }
  cout<<br1<<endl;
  return 0;
}
