#include<cstdio>
#include<iostream>
using namespace std;
long long p[20],n,result,pos[20],r;
int main()
{
  scanf("%llu",&n);
  //cout<<n<<endl;
  for(int i=0;i<n;i++)
  {
    scanf("%llu",&p[i]);
    pos[i]=i+1;
  }
  for(int i=0;i<n;i++)
  {
    r=0;
    while(p[i]!=pos[r])r++;
    result=result*(n-i)+r;
    for(int j=r+1;j<n;j++)
    {
      pos[j-1]=pos[j];
    }
  }
  cout<<result+1<<endl;
  return 0;
}
