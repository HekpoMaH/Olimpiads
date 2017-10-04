#include<iostream>
using namespace std;
int a[4],mnd=9999,fn,sn;
int main()
{
  cin>>a[0]>>a[1]>>a[2]>>a[3];
  sort(a,a+4);
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      if(i!=j)
      for(int k=0;k<4;k++)
      {
        for(int f=0;f<4;f++)
        {
          if(i!=k&&i!=f&&j!=k&&j!=f&&k!=f)
          {
            fn=a[i]*10+a[j];
            sn=a[k]*10+a[f];

            if(fn>sn&&fn-sn<mnd)mnd=fn-sn;
          }
        }
      }
    }
  }
  cout<<mnd<<endl;
  return 0;
}
