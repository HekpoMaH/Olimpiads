#include<iostream>
#include<algorithm>
using namespace std;
long long int s;
int n;
int mg[120];
long long int x3 = 2000000000;
int main()
{
  int mx =-1;
  int mx2 =-1;
  cin>>s>>n;
  for(int i=0;i<n;i++)
  {
   cin>>mg[i];
   if(mg[i]>mx&&mg[i]<=s)
   {
     mx=mg[i];
   }
  }
  int ost;
  int brt;
  ost = s%mx;
  brt = s/mx;
  sort(mg,mg+n);
  if(ost ==0)
  {
    x3 = brt;
  }

  else
  {
    for(int k= 0;k<n;k++)
    {
      mx = mg[k];
      ost = s%mx;
      brt = s/mx;
    for(int j = brt;j>=1;j--)
    {
      brt = j;
      ost = s-(mx*j);
    while(ost !=0)
      {
        mx2=1;
        for(int i=0;i<n;i++)
        {
          if(mg[i]>=mx2&&mg[i]<=ost&&mg[i]-mx!=0)
          {
            mx2=mg[i];
          }
        }
        brt+=ost/mx2;
        ost = ost%mx2;
      }
        if(brt < x3)
        {
          x3 =brt;
        }
      }
    }
  }
  cout<<x3<<endl;
  return 0;
}
