#include<iostream>
using namespace std;
int m,k,n[20];
int a[20][200],st[28],st1,st2,h,f[4008],d[4008],z,s[4008];
int main()
{
  cin>>m>>k;
  for(int i=0;i<m;i++)
  {
    cin>>n[i];
    for(int j=0;j<n[i];j++)
    {
      cin>>h;
      if(j==0)st[i]=h;
      a[i][h]++;
    }
  }
  st1=st[0];int tst;
  for(int j=0;j<=st[0];j++)f[j]=a[0][j];
  for(int i=1;i<m;i++)
  {
    tst=0;
    for(int j=0;j<i;j++)tst+=st[j];
    for(int j=0;j<=st[i];j++)d[j]=a[i][j];
    for(int j=0;j<=st[i];j++)
    {
      for(int e=0;e<=tst;e++)
      {
        z=j+e;
        s[z]+=f[e]*d[j];
      }
    }
    tst+=st[i];
    for(int r=0;r<=st[i]+tst;r++)f[r]=s[r];
    if(i!=m-1)for(int r=0;r<=st[i]+tst;r++)s[r]=0;
  }
  //for(
  cout<<s[k]<<endl;
  return 0;
}
