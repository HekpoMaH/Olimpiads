#include<iostream>
#include<string>
using namespace std;
int brw=0,brg=0,brr=0,n,wg,gr,w,g;
string a;
int findwing()
{
  for(int i=brw;i<brw+brg;i++)if(a[i]=='W'){return i;break;}
  return 0;
}
int findwinr()
{
  for(int i=brw+brg;i<n;i++)if(a[i]=='W'){return i;break;}
  return 0;
}
int findginr()
{
  for(int i=brw+brg;i<n;i++)if(a[i]=='G'){return i;break;}
  return 0;
}
int findring()
{
  for(int i=brw;i<brw+brg;i++)if(a[i]=='R'){return i;break;}
  return 0;
}
int main()
{

  getline(cin,a);
  n=a.size();

  for(int i=0;i<n;i++)
  {
    if(a[i]=='W')brw++;
    else
    if(a[i]=='G')brg++;
    else
    if(a[i]=='R')brr++;
  }
  wg=w;gr=w+g;
  int j1,j2;
  for(int i=0;i<brw;i++)
  {
    switch(a[i])
    {
      case 'G':
      j1=findwing();
      if(j1>0)
      {
        cout<<i+1<<" "<<j1+1<<endl;
        swap(a[i],a[j1]);
      }
      else
      {
        j1=findwinr();
        cout<<i+1<<" "<<j1+1<<endl;
        swap(a[i],a[j1]);
        j2=findring();
        cout<<j1+1<<" "<<j2+1<<endl;
        swap(a[j1],a[j2]);
      }
      break;
      case 'R':
      j1=findwinr();
      if(j1>0)
      {
        cout<<i+1<<" "<<j1+1<<endl;
        swap(a[i],a[j1]);
      }
      else
      {
        j1=findwing();
        cout<<i+1<<" "<<j1+1<<endl;
        swap(a[i],a[j1]);
        j2=findginr();
        cout<<j1+1<<" "<<j2+1<<endl;
        swap(a[j1],a[j2]);
      }
      break;
      case 'W':break;
    }
    for(int i=brw;i<brw+brg;i++)
    {
      if(a[i]=='R')
      {
        j1=findginr();
        cout<<i+1<<" "<<j1+1<<endl;
        swap(a[i],a[j1]);
      }
    }
  }
  return 0;
}
