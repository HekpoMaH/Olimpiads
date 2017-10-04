#include<iostream>
#include<deque>
using namespace std;
int a[100];
long long s,minbr=1000000000;
  int n,i,j,br,sum;

void rec()
{
if(sum==0)if(minbr>br)minbr=br;
  for(i=0;i<n;i++)
  {
    if(sum-a[i]>=0){br++;rec();}
  }
}

int main()
{
  cin>>s>>n;
  for(i=0;i<n;i++)
  cin>>a[i];

  for(i=0;i<n;i++)
  {
    sum=s;
    sum-=a[i];
    br++;
    rec();
  }

cout<<minbr<<endl;
  return 0;
}
/*

*/