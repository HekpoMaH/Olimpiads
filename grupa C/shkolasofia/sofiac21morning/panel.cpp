#include<iostream>
using namespace std;
long long a,b,c,w,h,n,k,ans=999999999999LL;
int main()
{
  cin>>w>>h>>n;
  //cout<<ans<<endl;
  a=0;
  b=max(w,h)*n;
  while(a<b)
  {
    c=(b+a)/2;
    k=(c/w)*(c/h);
    if(k>=n){b=c-1;if(c<ans)ans=c;}
    else{a=c+1;}
  }
  cout<<ans<<endl;
  return 0;
}
