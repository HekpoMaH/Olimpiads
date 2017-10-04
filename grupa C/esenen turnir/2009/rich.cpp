#include<cstdio>
#include<iostream>
using namespace std;
unsigned l[1001],bank,c,res,last;
int main()
{
  //ios::sync_with_stdio(false);
  while(scanf("%u",&bank))if(bank<=1000)l[bank]++;
  for(last=1001;l[last]==0; );
  for (int i=0;i<=last; i++ )if(l[i])
  {
    if(res>i){bank+=(res-i)*c;res=i;}
    //cout<<(res-i)*c<<endl;
    if(bank<c)break;
    res=i+bank/(c+=l[i]);
    bank%=c;
  }
  cout<<res<<endl;
  return 0;
}
