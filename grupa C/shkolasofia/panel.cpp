#include<iostream>
using namespace std;
long long w,h,n,a,b,c,k,tc=1000000000LL;
int main()
{
  cin>>w>>h>>n;
  a=0;b=max(w,h)*n;
  while(a<=b)
  {
    c=(a+b)/2;
    k=(c/w)*(c/h);
    //cout<<a<<" "<<b<<" "<<c<<" "<<k<<endl;
    //system("pause");
    if(k>=n)
    {
      if(k<tc)tc=c;
      b=c-1;
    }
    else a=c+1;
  }
  cout<<tc<<endl;
  return 0;
}
