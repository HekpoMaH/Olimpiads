#include<iostream>
using namespace std;
struct iztr
{
  int x,y;
};
long long int n,l=1,m,brl,br,bri;
string a[200];
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  iztr zi[1000];
  m=a[1].size();
  while(l==1)
  {
    for(int i=1;i<n-1;i++)
    {
      for(int j=1;j<m-1;j++)
      {
        brl=0;
        if(a[i][j]=='*')
        {
          if(a[i][j-1]=='0')brl++;
          if(a[i][j+1]=='0')brl++;
          if(a[i-1][j]=='0')brl++;
          if(a[i+1][j]=='0')brl++;
          if(brl>=2)
          {
            zi[bri].x=i;
            zi[bri].y=j;
            bri++;
          }
        }
      }
    }
    for(int i=0;i<bri;i++)a[zi[i].x][zi[i].y]='0';
    bri=0;
    l=0;
    for(int i=1;i<n-1;i++)
    {
      for(int j=1;j<m-1;j++)
      {
        if(a[i][j]=='*')
        {
          l=1;break;
        }
      }
    }
    br++;
  }
  cout<<br<<endl;
  return 0;
}
