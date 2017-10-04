#include<iostream>
using namespace std;
int main()
{
  double a,b;
  long long int br=0,maxbr=-1;
  cin>>a;b=a;
  if(a==0)cout<<0<<endl;
  else
  {
    br++;
    while(a!=0)
    {
      cin>>a;
      if(a>=b)br++;
      else br=1;
      if(br>maxbr)maxbr=br;
      //cout<<br<<" "<<maxbr<<" "<<b<<" "<<a<<endl;
      b=a;
    }
    cout<<maxbr<<endl;
  }
  return 0;
}
